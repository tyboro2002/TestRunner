#include "test.h"

void initializeTestRunner(TestRunner* runner, int passedTests, int totalTests){
    runner->passedTests = passedTests;
    runner->totalTests = totalTests;
}

void testResultTrue(TestRunner* runner, int condition, const char* testName) {
    runner->totalTests++;
    if (condition) {
        runner->passedTests++;
        //printf("[PASS] %s\n", testName);
    } else {
        runner->failedTests = realloc(runner->failedTests, (runner->totalTests - runner->passedTests) * sizeof(char*));
        runner->failedTests[runner->totalTests - runner->passedTests - 1] = strdup(testName);
        printf("[FAIL] %s\n", testName);
    }
}

void testResultFalse(TestRunner* runner, int condition, const char* testName) {
    testResultTrue(runner, !condition, testName);
}

void testScope1(TestRunner* runner) {
    // Implement your test case here
    int condition = 1; // Replace with your actual test condition
    testResultTrue(runner, condition, "testScope1");
}

void runAutomatedTestCases(TestRunner* runner) {
    // Run the tests
    testScope1(runner);


    // Print a summary
    printf("\n\nSummary: %d out of %d tests passed.\n", runner->passedTests, runner->totalTests);

    // Print the list of failed tests
    if (runner->failedTests) {
        printf("\nFailed Tests:\n");
        for (int i = 0; i < runner->totalTests - runner->passedTests; i++) {
            printf("  %s\n", runner->failedTests[i]);
        }
        free(runner->failedTests);
    }
}