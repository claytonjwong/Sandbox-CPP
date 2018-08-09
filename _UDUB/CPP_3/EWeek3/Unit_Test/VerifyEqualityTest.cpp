#include "TestHarness.h"
#include "Common.hpp"
#include "Word.hpp"
#include <iostream>


TEST(verifyEqualityTest, Word)
{
    const unsigned char input[]{ 0xAB, 0xCD, 0 };
    std::stringstream ss{reinterpret_cast<const char*>(input)};

    Binary::Word actual{ Binary::Word::readLittleEndian(ss) };
    const Binary::Word notReallyExpected{0xABCD};

    try
    {
        verifyEquality(notReallyExpected, actual, "notReallyExpected");
        CHECK(false);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        CHECK(true);
    }
}


