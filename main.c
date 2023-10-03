#include <stdio.h>
#include "test.h"

#define TEST 1 //define 1 if test run 0 if main code run

int main() {
#if TEST
    printf("tests:\n");
    TestRunner testRunner;
    initializeTestRunner(&testRunner, 0,0);
    runAutomatedTestCases(&testRunner);
    return 0;
#else
    printf("Hello, World!\n");
    return 0;
#endif
}
