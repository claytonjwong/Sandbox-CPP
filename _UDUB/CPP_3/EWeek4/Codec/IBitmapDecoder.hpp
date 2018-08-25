//
//  IBitmapDecoder.h
//  EWeek4
//
//  Created by CLAYTON WONG on 8/25/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "IBitmapIterator.hpp"


namespace Codec
{
    class IBitmapDecoder;
    using HBitmapDecoder = IBitmapDecoder*;

    class IBitmapDecoder
    {
    public:
    
        virtual ~IBitmapDecoder ( ) = 0;
        
        virtual HBitmapDecoder clone ( ) const noexcept = 0;
        
        virtual BitmapGraphics::HBitmapIterator createIterator ( ) const noexcept = 0;
        
        virtual std::string getMimeType ( ) const noexcept = 0;
        
        virtual bool isSupported ( ) const noexcept = 0;
        
    };
}
