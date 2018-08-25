//
//  WindowsBitmapDecoder.hpp
//  EWeek4
//
//  Created by CLAYTON WONG on 8/25/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "IBitmapDecoder.hpp"

namespace Codec
{
    class WindowsBitmapDecoder : public IBitmapDecoder
    {
        public:
            virtual ~WindowsBitmapDecoder ( );
        
            virtual HBitmapDecoder clone ( ) const noexcept override;
        
            virtual BitmapGraphics::HBitmapIterator createIterator ( ) const noexcept override;
        
            virtual std::string getMimeType ( ) const noexcept override;
        
            virtual bool isSupported ( ) const noexcept override;
    };
}
