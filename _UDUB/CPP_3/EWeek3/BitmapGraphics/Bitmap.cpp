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
    Bitmap::Bitmap ( int width, int height, std::istream& inStream ) :
    myWidth{ width },
    myHeight{ height },
    myPaddingSize{ 0 }
    {
        auto scanLineSize = Color::BYTE_COUNT * myWidth;
        auto align = Binary::DoubleWord::BYTE_COUNT;
        myPaddingSize = ( align - ( scanLineSize % align ) ) % align;
    
        for ( auto scanLineHeight = 0;  scanLineHeight < myHeight;  ++scanLineHeight )
        {
            readScanLine( inStream );
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
    
    void Bitmap::write ( std::ostream& outStream ) const
    {
        for ( const auto& scanLine: myScanLines )
        {
            writeScanLine( outStream, scanLine );
        }
    }
    
    void Bitmap::readScanLine ( std::istream& inStream ) noexcept
    {
        ScanLine scanLine;
        
        for ( auto width = 0;  width < myWidth;  ++width )
        {
            scanLine.emplace_back(  std::move( Color::read( inStream ) )  );
        }
        myScanLines.emplace_back(  std::move( scanLine )  );
    
        readPadding( inStream );
    }
    
    void Bitmap::writeScanLine ( std::ostream& outStream, const ScanLine& scanLine ) const
    {
        for ( const auto& color: scanLine )
        {
            color.write( outStream );
        }
        
        writePadding( outStream );
    }
    
    void Bitmap::readPadding ( std::istream& inStream ) const noexcept
    {
        for ( auto padCount = 0;  padCount < myPaddingSize; ++padCount )
        {
            inStream.ignore();
        }
    }

    void Bitmap::writePadding ( std::ostream& outStream ) const noexcept
    {
        Binary::Byte padding;
        for ( auto padCount = 0; padCount < myPaddingSize; ++padCount )
        {
            padding.write( outStream );
        }
    }
    
    std::ostream& operator<< ( std::ostream& outStream, const Bitmap& rhs )
    {
        rhs.write( outStream );
        return outStream;
    }
}
