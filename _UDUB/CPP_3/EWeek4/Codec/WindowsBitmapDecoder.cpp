//
//  WindowsBitmapDecoder.cpp
//  EWeek4
//
//  Created by CLAYTON WONG on 8/25/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "WindowsBitmapDecoder.hpp"
#include "IBitmapDecoder.hpp"
#include "IBitmapIterator.hpp"
#include "BitmapIterator.hpp"
#include "WindowsBitmapHeader.hpp"
#include "Bitmap.hpp"
#include <iostream>
#include <sstream>

namespace Codec
{
    WindowsBitmapDecoder::WindowsBitmapDecoder ( ) :
    myMimeType{ "image/x-ms-bmp" }
    {
    }
    
    HBitmapDecoder WindowsBitmapDecoder::clone ( std::istream& inStream ) noexcept
    {
        auto result = std::make_shared<WindowsBitmapDecoder>();
        result->myStream << inStream.rdbuf();
        BitmapGraphics::WindowsBitmapHeader header{ result->myStream };
        result->myBitmap = BitmapGraphics::Bitmap{
            header.getBitmapWidth(), header.getBitmapHeight(), result->myStream };
        return result;
    }
    
    BitmapGraphics::HBitmapIterator WindowsBitmapDecoder::createIterator ( ) const noexcept
    {
        auto it = BitmapGraphics::BitmapIterator{ myBitmap };
        return std::make_shared<BitmapGraphics::BitmapIterator>( it );
    }
    
    const std::string& WindowsBitmapDecoder::getMimeType ( ) const noexcept
    {
        return myMimeType;
    }

    bool WindowsBitmapDecoder::isSupported ( ) const noexcept
    {
        return true; // TODO: provide first 100 bytes in stream here,
    }
}
