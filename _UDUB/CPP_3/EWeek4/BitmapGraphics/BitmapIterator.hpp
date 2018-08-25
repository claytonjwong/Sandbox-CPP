//
//  BitmapIterator.hpp
//  EWeek4
//
//  Created by CLAYTON WONG on 8/25/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Bitmap.hpp"
#include "IBitmapIterator.hpp"

namespace BitmapGraphics
{
    class BitmapIterator : public IBitmapIterator
    {
    public:
    
        BitmapIterator ( const BitmapGraphics::Bitmap& bitmap ) :
        myBitmap{ bitmap },
        myCurrScanLine{ myBitmap.begin() },
        myCurrPixel{ myCurrScanLine->begin() }
        {
        }
        
        virtual ~BitmapIterator ( ) = default;
    
        virtual Color getColor ( ) const noexcept override
        {
            return *myCurrPixel;
        }
        
        virtual int getBitmapWidth ( ) const noexcept override
        {
            return myBitmap.getWidth();
        }
        
        virtual int getBitmapHeight ( ) const noexcept override
        {
            return myBitmap.getHeight();
        }
        
        virtual bool isEndOfImage ( ) const noexcept override
        {
            return myCurrScanLine == myBitmap.end();
        }
        
        virtual bool isEndOfScanLine ( ) const noexcept override
        {
            return myCurrPixel == myCurrScanLine->end();
        }
        
        virtual void nextScanLine ( ) override
        {
            if ( isEndOfImage() )
            {
                throw std::runtime_error{ "cannot retrieve next scan line, currently at end of image" };
            }
            
            ++myCurrScanLine;
            myCurrPixel = myCurrScanLine->begin();
        }
        
        virtual void nextPixel ( ) override
        {
            if ( isEndOfScanLine() )
            {
                throw std::runtime_error{ "cannot retrieve next pixel, current at end of scan line" };
            }
            
            ++myCurrPixel;
        }
        
        
        
    private:
    
        const Bitmap& myBitmap;
        Bitmap::ScanLineIterator myCurrScanLine;
        Bitmap::PixelIterator myCurrPixel;
    };
}
