#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TestRunner_ {
    int passedTests;
    int totalTests;
    char** failedTests;
} TestRunner;

void initializeTestRunner(TestRunner* runner, int passedTests, int totalTests);

void testResultTrue(TestRunner* runner, int condition, const char* testName);
void testResultFalse(TestRunner* runner, int condition, const char* testName);
void testScope1(TestRunner* runner);

void runAutomatedTestCases(TestRunner* runner);