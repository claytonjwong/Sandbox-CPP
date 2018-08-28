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
    
        BitmapIterator ( ) = delete;
    
        BitmapIterator ( BitmapGraphics::HBitmapHeader header, const BitmapGraphics::Bitmap& bitmap ) :
        myHeader{ header },
        myWidth{ bitmap.getWidth() },
        myHeight{ bitmap.getHeight() },
        myNumberOfPadBytes{ bitmap.getNumberOfPadBytes() },
        myCurrScanLine{ bitmap.begin() },
        myEndOfScanLines{ bitmap.end() },
        myCurrPixel{ myCurrScanLine->begin() }
        {
        }
        
        virtual ~BitmapIterator ( ) = default;
    
        virtual HBitmapHeader getBitmapHeader ( ) const noexcept override
        {
            return myHeader;
        }
    
        virtual Color getColor ( ) const noexcept override
        {
            return *myCurrPixel;
        }
        
        virtual int getBitmapWidth ( ) const noexcept override
        {
            return myWidth;
        }
        
        virtual int getBitmapHeight ( ) const noexcept override
        {
            return myHeight;
        }
        
        virtual int getBitmapNumberOfPadBytes ( ) const noexcept override
        {
            return myNumberOfPadBytes;
        }
        
        virtual bool isEndOfImage ( ) const noexcept override
        {
            return myCurrScanLine == myEndOfScanLines;
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
        HBitmapHeader myHeader;
        const int myWidth, myHeight, myNumberOfPadBytes;
        Bitmap::ScanLineIterator myCurrScanLine;
        Bitmap::ScanLineIterator myEndOfScanLines;
        Bitmap::PixelIterator myCurrPixel;
    };
}
