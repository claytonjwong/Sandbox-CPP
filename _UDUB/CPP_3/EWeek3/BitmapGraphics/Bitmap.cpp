//
//  Bitmap.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "DoubleWord.hpp"
#include "Color.hpp"
#include "Bitmap.hpp"

namespace BitmapGraphics
{
    Bitmap::Bitmap ( int width, int height, std::istream& is ) :
    myWidth{ width },
    myHeight{ height },
    myPaddingSize{ 0 }
    {
        int scanLineSize = Color::BYTE_COUNT * myWidth;
        int align = Binary::DoubleWord::BYTE_COUNT;
        myPaddingSize = ( align - ( scanLineSize % align ) ) % align;
    
        for ( int i = 0;  i < myHeight;  ++i )
        {
            readScanLine( is );
        }
    }
    
    int Bitmap::getWidth() const noexcept
    {
        return myWidth;
    }

    int Bitmap::getHeight() const noexcept
    {
        return myHeight;
    }
    
    int Bitmap::getNumberOfPadBytes() const noexcept
    {
        return myPaddingSize;
    }

    Bitmap::ScanLineIterator Bitmap::begin() const noexcept
    {
        return myScanLines.begin();
    }

    Bitmap::ScanLineIterator Bitmap::end() const noexcept
    {
        return myScanLines.end();
    }
    
    void Bitmap::write ( std::ostream& os ) const
    {
        for ( const auto& scanLine: myScanLines )
        {
            writeScanLine( os, scanLine );
        }
    }
    
    void Bitmap::readScanLine ( std::istream& is )
    {
        ScanLine scanLine;
        for ( int j = 0;  j < myWidth;  ++j )
        {
            auto color = Color::read( is );
            scanLine.emplace_back(  std::move( color )  );
        }
        myScanLines.emplace_back(  std::move( scanLine )  );
    
        readPadding( is );
    }
    
    void Bitmap::writeScanLine ( std::ostream& os, const ScanLine& scanLine ) const
    {
        for ( const auto& color: scanLine )
        {
            color.write( os );
        }
        
        writePadding( os );
    }
    
    void Bitmap::readPadding ( std::istream& is ) const noexcept
    {
        for ( int p = 0;  p < myPaddingSize; ++p)
        {
            is.ignore();
        }
    }

    void Bitmap::writePadding ( std::ostream& os ) const noexcept
    {
        Binary::Byte padding;
        for ( int p = 0; p < myPaddingSize; ++p )
        {
            padding.write( os );
        }
    }
    
    std::ostream& operator<< ( std::ostream& os, const Bitmap& bitmap )
    {
        bitmap.write( os );
        return os;
    }
}
