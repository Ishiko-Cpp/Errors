/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Errors/blob/master/LICENSE.txt
*/

#include "StreamUtilitiesTests.h"
#include "Ishiko/Errors/StreamUtilities.h"
#include <fstream>

using namespace Ishiko;
using namespace Ishiko::Tests;

StreamUtilitiesTests::StreamUtilitiesTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "StreamUtilities tests", environment)
{
    append<HeapAllocationErrorsTest>("FailOnFileCreationError test 1", FailOnFileCreationErrorTest1);
    append<HeapAllocationErrorsTest>("FailOnFileCreationError test 2", FailOnFileCreationErrorTest2);
}

void StreamUtilitiesTests::FailOnFileCreationErrorTest1(Test& test)
{
    Ishiko::Error error;
    std::fstream file("doesnotexist");

    bool failed = FailOnFileCreationError(error, file);
  
    ISHTF_FAIL_IF_NOT(failed);
    ISHTF_FAIL_IF_NOT(error);
    ISHTF_FAIL_IF_NEQ(error.condition().value(), -2);
    ISHTF_FAIL_IF_NEQ(&error.condition().category(), &IOErrorCategory::Get());

    const char* originFile = nullptr;
    int originLine = -1;
    bool origin = error.tryGetOrigin(originFile, originLine);

    ISHTF_FAIL_IF(origin);
    ISHTF_PASS();
}

void StreamUtilitiesTests::FailOnFileCreationErrorTest2(Test& test)
{
    const char* path = "doesnotexist";

    Ishiko::Error error(new Ishiko::MessageErrorExtension());;
    std::fstream file(path);

    bool failed = FailOnFileCreationError(error, file, path, "file1", 3);

    ISHTF_FAIL_IF_NOT(failed);
    ISHTF_FAIL_IF_NOT(error);
    ISHTF_FAIL_IF_NEQ(error.condition().value(), -2);
    ISHTF_FAIL_IF_NEQ(&error.condition().category(), &IOErrorCategory::Get());

    const char* originFile = nullptr;
    int originLine = -1;
    bool origin = error.tryGetOrigin(originFile, originLine);

    ISHTF_FAIL_IF_NOT(origin);
    ISHTF_FAIL_IF_STR_NEQ(originFile, "file1");
    ISHTF_FAIL_IF_NEQ(originLine, 3);
    ISHTF_PASS();
}