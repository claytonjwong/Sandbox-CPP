#include "TestHarness.h"
#include "Bitmap.hpp"
#include "WindowsBitmapDecoder.hpp"
#include "WindowsBitmapEncoder.hpp"
#include "BitmapIterator.hpp"
#include "binary_ostream_iterator.hpp"
#include <fstream>

using namespace BitmapGraphics;
using namespace Codec;

TEST(createDecoder, WindowsBitmapDecoder)
{
    std::ifstream bitmapStream{"basic.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder{decoderPrototype.clone(bitmapStream)};
    CHECK_EQUAL("image/x-ms-bmp", decoder->getMimeType());
}


TEST(BitmapSizeTest, BitmapIterator)
{
    std::ifstream bitmapStream{"basic.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder {decoderPrototype.clone(bitmapStream)};
    HBitmapIterator bitmapIter {decoder->createIterator()};
    
    CHECK_EQUAL(100, bitmapIter->getBitmapWidth());
    CHECK_EQUAL(100, bitmapIter->getBitmapHeight());
}


TEST(BitmapScanLinesTest, BitmapIterator)
{
    std::ifstream bitmapStream{"basic.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder {decoderPrototype.clone(bitmapStream)};
    HBitmapIterator bitmapIter {decoder->createIterator()};

    int numberOfScanLines{0};
    while (! bitmapIter->isEndOfImage())
    {
        int numberOfPixelsInScanLine{0};
        while (! bitmapIter->isEndOfScanLine())
        {
            ++numberOfPixelsInScanLine;
            bitmapIter->nextPixel();
        }
        CHECK_EQUAL(100, numberOfPixelsInScanLine);
        ++numberOfScanLines;
        
        bitmapIter->nextScanLine();
    }
    CHECK_EQUAL(100, numberOfScanLines);
}

