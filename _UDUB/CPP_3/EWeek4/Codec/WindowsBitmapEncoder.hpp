//
//  WindowsBitmapEncoder.hpp
//  EWeek4
//
//  Created by CLAYTON WONG on 8/26/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "IBitmapEncoder.hpp"
#include "IBitmapIterator.hpp"
#include "Byte.hpp"
#include <iostream>

namespace Codec
{
    class WindowsBitmapEncoder : public IBitmapEncoder
    {
    public:
        
        WindowsBitmapEncoder ( ) = default;
        
        virtual ~WindowsBitmapEncoder ( ) = default;
        
        virtual HBitmapEncoder clone ( BitmapGraphics::HBitmapIterator it ) noexcept
        {
            auto result = std::make_shared<WindowsBitmapEncoder>();
            result->myIt = it;
            return result;
        }
        
        virtual void encodeToStream ( std::ostream& outStream ) const noexcept
        {
            auto header = myIt->getBitmapHeader();
            if ( header )
            {
                header->write( outStream );
            }
            else
            {
                throw std::runtime_error{ "unable to retrieve header from iterator, cannot write header to stream" };
            }
            
            for ( auto it=myIt; ! it->isEndOfImage(); it->nextScanLine() )
            {
                for ( ; ! it->isEndOfScanLine(); it->nextPixel() )
                {
                    outStream << it->getColor();
                }
                
                Binary::Byte padByte{ 0 };
                for ( int pad = 0u; pad < it->getBitmapNumberOfPadBytes(); ++pad )
                {
                    outStream << padByte;
                }
            }
        }
        
    private:
        BitmapGraphics::HBitmapIterator myIt;
    };
}
