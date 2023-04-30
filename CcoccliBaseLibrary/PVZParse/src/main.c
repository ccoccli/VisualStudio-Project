#include "main.h"

typedef unsigned char byte_t;

struct FileInfoNode;
typedef struct FileInfoNode FileInfoNode;
struct FileInfoNode
{
	char * pPathname;
	unsigned int fileSize;
	FileInfoNode * pNext;
};

int main(void)
{
	printf("===Welcome!===\n");

	FILE * fpMainPak = fopen("main.pak", "rb");
	if (NULL == fpMainPak)
	{
		fprintf(stderr, "ERROR : Failed to open file \"main.pak\".\n");
		exit(EXIT_FAILURE);
	}

	fseek(fpMainPak, 0, SEEK_END);
	long sizeMainPak = ftell(fpMainPak);
	rewind(fpMainPak);

	if ( !(sizeMainPak > 0) )
	{
		fprintf(stderr, "ERROR : Size of file \"main.pak\" must be greater than zero.\n");
		exit(EXIT_FAILURE);
	}

	printf("Loading \"main.pak\"...");
	byte_t * pMainPak = (byte_t *)malloc(sizeMainPak);

	if (NULL == pMainPak)
	{
		fprintf(stderr, "ERROR : Failed to allocate memory for the memory image of file \"main.pak\".\n");
		exit(EXIT_FAILURE);
	}
	if (fread(pMainPak, sizeof (byte_t), sizeMainPak, fpMainPak) != sizeMainPak)
	{
		fprintf(stderr, "ERROR : Failed to load file \"main.pak\" to memory.\n");
		exit(EXIT_FAILURE);
	}
	printf("[Finished!]\n");

	fclose(fpMainPak);
	fpMainPak = NULL;

	printf("Decrypting data...");
	for (int i = 0; i < sizeMainPak; i += 1)
		pMainPak[i] ^= (byte_t)0xF7;

	printf("[Finished!]\n");

	FileInfoNode headNode;
	headNode.pNext = NULL;
	
	FileInfoNode * pNode = &headNode;

	unsigned int byteIndex = 0;

	printf("Scanning files...");
	while (1){
		byteIndex += 8;
		if (0 != pMainPak[byteIndex])
		{
			byteIndex += 1;
			break;
		}

		pNode->pNext = (FileInfoNode *)malloc(sizeof (FileInfoNode));
		pNode = pNode->pNext;
		if (NULL == pNode)
		{
			fprintf(stderr, "ERROR : Failed to allocate memory for new FileInfoNode.\n");
			exit(EXIT_FAILURE);
		}
		pNode->pNext = NULL;

		byteIndex += 1;
		pNode->pPathname = (char *)malloc(pMainPak[byteIndex] + 1);
		if (NULL == pNode->pPathname){
			fprintf(stderr, "ERROR : Failed to allocate memory for Pathname linked to FileInfoNode.\n");
			exit(EXIT_FAILURE);
		}
		(pNode->pPathname)[pMainPak[byteIndex]] = '\0';
		//复制文件名
		for (int i = 0; i < pMainPak[byteIndex]; i += 1)
			(pNode->pPathname)[i] = pMainPak[byteIndex + 1 + i];

		byteIndex += 1 + pMainPak[byteIndex];
		pNode->fileSize = *((unsigned int *)(pMainPak + byteIndex));

		byteIndex += 4;
	}
	printf("[Finished!]\n");

	{
		unsigned int totalSize = 0;
		for (pNode = headNode.pNext; pNode != NULL; pNode = pNode->pNext)
			totalSize += pNode->fileSize;
		if (totalSize != sizeMainPak - byteIndex)
		{
			fprintf(stderr, "ERROR : Size of file \"main.pak\" is unexpected.\n");
			exit(EXIT_FAILURE);
		}
	}

	printf("Releasing files(Please wait patiently)...");
	for (pNode = headNode.pNext; pNode != NULL; pNode = pNode->pNext)
	{
		{
			char * pSlash = pNode->pPathname;
			while (1)
			{
				while ( !(*pSlash == '\\' || *pSlash == '\0') )
					pSlash += 1;
				if ('\0' == *pSlash)
					break;

				*pSlash = '\0';
				if (-1 == _access(pNode->pPathname, F_OK))
					_mkdir(pNode->pPathname);

				*pSlash = '\\';

				pSlash += 1;
			}
		}

		FILE * fpRelease = fopen(pNode->pPathname, "wb");
		if (NULL == fpRelease)
		{
			fprintf(stderr, "ERROR : Failed to open file to be written.\n");
			exit(EXIT_FAILURE);
		}

		if (fwrite(pMainPak + byteIndex, sizeof (byte_t), pNode->fileSize, fpRelease) != pNode->fileSize){
			fprintf(stderr, "ERROR : An error occurred while writting.\n");
			exit(EXIT_FAILURE);
		}

		fclose(fpRelease);
		fpRelease = NULL;

		byteIndex += pNode->fileSize;
	}
	printf("[Finished!]\n");

	pNode = headNode.pNext;
	headNode.pNext = NULL;
	while (pNode != NULL)
	{
		FileInfoNode * pNextNode = pNode->pNext;
		free(pNode->pPathname);
		free(pNode);
		pNode = pNextNode;
	}

	free(pMainPak);
	pMainPak = NULL;

	printf("===Success!===\n");
	return 0;
}