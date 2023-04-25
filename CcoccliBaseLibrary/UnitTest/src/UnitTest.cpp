#include "UnitTest.h"

ci main()
{
#ifdef DEBUGTEST
  DebugTest();
#endif

#ifdef BASESTRTEST
  BaseStringTest();
#endif
}

#ifdef DEBUGTEST
cv DebugTest()
{
  cc str[] = "!";
  LIB_DEBUG("this is lib debug test %s\n", str);
  APP_DEBUG("this is app debug test %s\n", str);
}
#endif

#define BASESTRTEST
#ifdef BASESTRTEST
cv BaseStringTest()
{
  cc str1[] = "Hello world !";
  cc str2[20];

  BaseString::co_memcpy(str2, str1, sizeof(str1));

  LIB_DEBUG("str1 is %s\n", str1);
  LIB_DEBUG("str2 is %s\n", str2);
  system("pause");
}
#endif