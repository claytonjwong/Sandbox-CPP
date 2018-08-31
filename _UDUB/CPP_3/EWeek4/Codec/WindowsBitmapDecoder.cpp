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
#include "CodecLibrary.hpp"
#include <iostream>
#include <sstream>
#include <memory>

namespace Codec
{
    WindowsBitmapDecoder::WindowsBitmapDecoder ( ) :
    myMimeType{ MimeType::WINDOWS_BITMAP }
    {
    }
    
    HBitmapDecoder WindowsBitmapDecoder::clone ( std::istream& inStream )
    {
        auto result = std::make_shared<WindowsBitmapDecoder>();
        result->myStream << inStream.rdbuf();
        
        if ( ! result->myStream.str().empty() )
        {
            if ( ! isSupported( result->myStream.str().substr( 0, 100 ) ) ) // use first 100 bytes to check if supported
            {
                throw std::runtime_error{ "unsupported format" };
            }
            
            BitmapGraphics::WindowsBitmapHeader header{ result->myStream };
            result->myBitmap = std::make_unique<BitmapGraphics::Bitmap>(
                BitmapGraphics::Bitmap{
                    header.getBitmapWidth(), header.getBitmapHeight(), result->myStream }  );
        }
        
        return result;
    }
    
    BitmapGraphics::HBitmapIterator WindowsBitmapDecoder::createIterator ( ) const
    {
        if ( myBitmap == nullptr )
        {
            throw std::runtime_error{ "myBitmap is null" };
        }
        
        auto it = BitmapGraphics::BitmapIterator{ *myBitmap };
        return std::make_shared<BitmapGraphics::BitmapIterator>( it );
    }
    
    const std::string& WindowsBitmapDecoder::getMimeType ( ) const noexcept
    {
        return myMimeType;
    }

    bool WindowsBitmapDecoder::isSupported ( const std::string& firstChunkOfBitmap ) const noexcept
    {
        return firstChunkOfBitmap[0] == 'B' && firstChunkOfBitmap[1] == 'M';
    }
}
