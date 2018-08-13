//
//  WindowsBitmapHeader.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "WindowsBitmapHeader.hpp"
#include <sstream>

using namespace Binary;

namespace BitmapGraphics
{
    //
    // file header: https://en.wikipedia.org/wiki/BMP_file_format#Bitmap_file_header
    //
    const Byte WindowsBitmapHeader::firstIdentifier{ 'B' };
    const Byte WindowsBitmapHeader::secondIdentifier{ 'M' };
    // << myFileSize >>
    const DoubleWord WindowsBitmapHeader::reserved{ 0 };
    const DoubleWord WindowsBitmapHeader::rawImageOffset{ FILE_HEADER_SIZE + INFO_HEADER_SIZE };
    
    //
    // info header: https://en.wikipedia.org/wiki/BMP_file_format#DIB_header_(bitmap_information_header)
    //
    const DoubleWord WindowsBitmapHeader::infoHeaderSize{ INFO_HEADER_SIZE };
    // << myWidth >>
    // << myHeight >>
    const Word WindowsBitmapHeader::colorPlanes{ 1 };
    const Word WindowsBitmapHeader::colorDepth{ 24 };
    const DoubleWord WindowsBitmapHeader::compressionMethod{ 0 };
    // << myImageSize >>
    // << myHorizontalPixelsPerMeter >>
    // << myVerticalPixelsPerMeter >>
    const Binary::DoubleWord WindowsBitmapHeader::numberOfColors{ 0 };
    const Binary::DoubleWord WindowsBitmapHeader::numberOfImportantColors{ 0 };


    WindowsBitmapHeader::WindowsBitmapHeader ( std::istream& is )
    {
        readFileHeader( is );
        readInfoHeader( is );
    }
    
    //
    // order of read() matters based on the file header!
    //
    // file header: https://en.wikipedia.org/wiki/BMP_file_format#Bitmap_file_header
    //
    void WindowsBitmapHeader::readFileHeader ( std::istream& is )
    {
        verifyEquality( static_cast<std::streampos>( 0 ), is.tellg(), "myFirstIdentifier position" );
        verifyEquality( firstIdentifier, Byte::read( is ), "myFirstIdentifier value" );

        verifyEquality( static_cast<std::streampos>( 1 ), is.tellg(), "mySecondIdentifier position" );
        verifyEquality( secondIdentifier, Byte::read( is ), "mySecondIdentifier value");
        
        verifyEquality( static_cast<std::streampos>( 2 ), is.tellg(), "myFileSize position" );
        myFileSize = DoubleWord::readLittleEndian( is );
        
        verifyEquality( static_cast<std::streampos>( 6 ), is.tellg(), "reserved position" );
        verifyEquality( reserved, DoubleWord::readLittleEndian( is ), "reserved value" );
        
        verifyEquality( static_cast<std::streampos>( 10 ), is.tellg(), "rawImageOffset position" );
        verifyEquality( rawImageOffset, DoubleWord::readLittleEndian( is ), "rawImageOffset value" );
    }
    
    //
    // order of read() matters based on the info header!
    //
    // info header: https://en.wikipedia.org/wiki/BMP_file_format#DIB_header_(bitmap_information_header)
    //
    void WindowsBitmapHeader::readInfoHeader ( std::istream& is )
    {
        verifyEquality( static_cast<std::streampos>( 14 ), is.tellg(), "infoHeaderSize position" );
        verifyEquality( infoHeaderSize, DoubleWord::readLittleEndian( is ), "infoHeaderSize value" );
        
        verifyEquality( static_cast<std::streampos>( 18 ), is.tellg(), "myWidth position" );
        myWidth = DoubleWord::readLittleEndian( is );
        
        verifyEquality( static_cast<std::streampos>( 22 ), is.tellg(), "myHeight position" );
        myHeight = DoubleWord::readLittleEndian( is );
        
        verifyEquality( static_cast<std::streampos>( 26 ), is.tellg(), "colorPlanes position" );
        verifyEquality( colorPlanes, Word::readLittleEndian( is ), "colorPlanes value" );
        
        verifyEquality( static_cast<std::streampos>( 28 ), is.tellg(), "colorDepth position" );
        verifyEquality( colorDepth, Word::readLittleEndian( is ), "colorDepth value" );
        
        verifyEquality( static_cast<std::streampos>( 30 ), is.tellg(), "compressionMethod position" );
        verifyEquality( compressionMethod, DoubleWord::readLittleEndian( is ), "compressionMethod value" );
        
        verifyEquality( static_cast<std::streampos>( 34 ), is.tellg(), "myImageSize position" );
        myImageSize = DoubleWord::readLittleEndian( is );
        
        verifyEquality( static_cast<std::streampos>( 38 ), is.tellg(), "myHorizontalPixelsPerMeter position" );
        myHorizontalPixelsPerMeter = DoubleWord::readLittleEndian( is );
        
        verifyEquality( static_cast<std::streampos>( 42 ), is.tellg(), "myVerticalPixelsPerMeter position" );
        myVerticalPixelsPerMeter = DoubleWord::readLittleEndian( is );
        
        DoubleWord ignoreValue{ 0 };
        verifyEquality( static_cast<std::streampos>( 46 ), is.tellg(), "myVerticalPixelsPerMeter position" );
        ignoreValue = DoubleWord::readLittleEndian( is ); // numberOfColors
        
        verifyEquality( static_cast<std::streampos>( 50 ), is.tellg(), "myVerticalPixelsPerMeter position" );
        ignoreValue = DoubleWord::readLittleEndian( is ); // numberOfImportantColors
        
        verifyEquality( static_cast<std::streampos>( 54 ), is.tellg(), "end info header" );
    }
    
    int WindowsBitmapHeader::getBitmapWidth() const noexcept
    {
        return myWidth;
    }
    
    int WindowsBitmapHeader::getBitmapHeight() const noexcept
    {
        return myHeight;
    }
    
    int WindowsBitmapHeader::getFileSize() const noexcept
    {
        return myFileSize;
    }
    
    void WindowsBitmapHeader::write ( std::ostream& os ) const
    {
        writeFileHeader( os );
        writeInfoHeader( os );
    }
    
    void WindowsBitmapHeader::writeFileHeader ( std::ostream& os ) const
    {
        firstIdentifier.write( os );
        secondIdentifier.write( os );
        myFileSize.write( os );
        reserved.write( os );
        rawImageOffset.write( os );
    }
    void WindowsBitmapHeader::writeInfoHeader ( std::ostream& os ) const
    {
        infoHeaderSize.write( os );
        myWidth.write( os );
        myHeight.write( os );
        colorPlanes.write( os );
        colorDepth.write( os );
        compressionMethod.write( os );
        myImageSize.write( os );
        myHorizontalPixelsPerMeter.write( os );
        myVerticalPixelsPerMeter.write( os );
        numberOfColors.write( os );
        numberOfImportantColors.write( os );
    }
}
