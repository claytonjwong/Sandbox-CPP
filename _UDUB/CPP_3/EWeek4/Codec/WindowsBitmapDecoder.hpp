//
//  WindowsBitmapDecoder.hpp
//  EWeek4
//
//  Created by CLAYTON WONG on 8/25/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "IBitmapDecoder.hpp"
#include "IBitmapIterator.hpp"
#include "BitmapIterator.hpp"
#include "WindowsBitmapHeader.hpp"
#include "Bitmap.hpp"
#include <iostream>
#include <sstream>

namespace Codec
{
    static constexpr std::string_view WINDOWS_BITMAP_MIME_TYPE = "image/x-ms-bmp";

    class WindowsBitmapDecoder : public IBitmapDecoder
    {
        public:
        
            WindowsBitmapDecoder ( ); // TODO: make singleton?
        
            virtual ~WindowsBitmapDecoder ( ) = default;
        
            WindowsBitmapDecoder ( const WindowsBitmapDecoder& src ) = delete;
            WindowsBitmapDecoder ( WindowsBitmapDecoder&& src ) = delete;
        
            WindowsBitmapDecoder& operator= ( const WindowsBitmapDecoder& rhs ) = delete;
            WindowsBitmapDecoder& operator= ( WindowsBitmapDecoder&& rhs ) = delete;
        
            virtual HBitmapDecoder clone ( std::istream& inStream ) noexcept override;
        
            virtual BitmapGraphics::HBitmapIterator createIterator ( ) const override;
        
            virtual const std::string& getMimeType ( ) const noexcept override;
        
            virtual bool isSupported ( ) const noexcept override;
        
        private:
        
            std::stringstream myStream;
            const std::string myMimeType;
            std::unique_ptr<BitmapGraphics::Bitmap> myBitmap;
    };
    
}
