#include "UnitTest.h"

ci main()
{
#ifdef DEBUGTEST
  DebugTest();
#endif

#ifdef SLLTEST
  SignedLinkedListTest();
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

#define SLLTEST
#ifdef SLLTEST
cv SignedLinkedListTest()
{
  LinkList<ci> lis;

  lis.Init_linklist();
  lis.Insert_linklist(0, 1);

  ci pos = lis.find_linklist(1);

  std::cout << pos << std::endl;

  system("pause");
}
#endif