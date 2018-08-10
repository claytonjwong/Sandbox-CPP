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
    const Binary::DoubleWord WindowsBitmapHeader::horizontalPixelsPerMeter{ 0 };
    const Binary::DoubleWord WindowsBitmapHeader::verticalPixelsPerMeter{ 0 };
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
        verifyEquality( firstIdentifier, Byte::read( is ), "myFirstIdentifier" );
        verifyEquality( secondIdentifier, Byte::read( is ), "mySecondIdentifier");
        myFileSize = DoubleWord::readLittleEndian( is );
        verifyEquality( reserved, DoubleWord::readLittleEndian( is ), "reserved" );
        verifyEquality( rawImageOffset, DoubleWord::readLittleEndian( is ), "rawImageOffset" );
    }
    
    //
    // order of read() matters based on the info header!
    //
    // info header: https://en.wikipedia.org/wiki/BMP_file_format#DIB_header_(bitmap_information_header)
    //
    void WindowsBitmapHeader::readInfoHeader ( std::istream& is )
    {
        verifyEquality( infoHeaderSize, DoubleWord::readLittleEndian( is ), "infoHeaderSize" );
        myWidth = DoubleWord::readLittleEndian( is );
        myHeight = DoubleWord::readLittleEndian( is );
        verifyEquality( colorPlanes, Word::readLittleEndian( is ), "colorPlanes" );
        verifyEquality( colorDepth, Word::readLittleEndian( is ), "colorDepth" );
        verifyEquality( compressionMethod, DoubleWord::readLittleEndian( is ), "compressionMethod" );
        myImageSize = DoubleWord::readLittleEndian( is );
        
        DoubleWord ignoreValue{ 0 };
        ignoreValue = DoubleWord::readLittleEndian( is ); // horizontalPixelsPerMeter
        ignoreValue = DoubleWord::readLittleEndian( is ); // verticalPixelsPerMeter
        ignoreValue = DoubleWord::readLittleEndian( is ); // numberOfColors
        ignoreValue = DoubleWord::readLittleEndian( is ); // numberOfImportantColors
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
    
    void WindowsBitmapHeader::write ( std::ostream& os )
    {
        writeFileHeader( os );
        writeInfoHeader( os );
    }
}
