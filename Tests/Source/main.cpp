/*
    Copyright (c) 2019-2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Errors/blob/master/LICENSE.txt
*/

#include "ErrorConditionTests.h"
#include "ErrorTests.h"
#include "MessageErrorExtensionTests.h"
#include "IOErrorExtensionTests.h"
#include "ChainErrorExtensionTests.h"
#include "Ishiko/TestFramework/TestFrameworkCore.h"

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoErrors");

    theTestHarness.environment().setTestDataDirectory("../../TestData");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<ErrorConditionTests>();
    theTests.append<ErrorTests>();
    theTests.append<MessageErrorExtensionTests>();
    theTests.append<IOErrorExtensionTests>();
    theTests.append<ChainErrorExtensionTests>();

    return theTestHarness.run();
}
