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
        auto scanLineSize = Color::BYTE_COUNT * myWidth;
        auto align = Binary::DoubleWord::BYTE_COUNT;
        myPaddingSize = ( align - ( scanLineSize % align ) ) % align;
    
        for ( auto scanLineHeight = 0;  scanLineHeight < myHeight;  ++scanLineHeight )
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
        
        for ( auto width = 0;  width < myWidth;  ++width )
        {
            scanLine.emplace_back(  std::move(Color::read( is ))  );
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
        for ( auto padCount = 0;  padCount < myPaddingSize; ++padCount)
        {
            is.ignore();
        }
    }

    void Bitmap::writePadding ( std::ostream& os ) const noexcept
    {
        Binary::Byte padding;
        for ( auto padCount = 0; padCount < myPaddingSize; ++padCount )
        {
            padding.write( os );
        }
    }
    
    std::ostream& operator<< ( std::ostream& os, const Bitmap& rhs )
    {
        rhs.write( os );
        return os;
    }
}
