//
//  WindowsBitmapHeader.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "WindowsBitmapHeader.hpp"
#include <sstream>

namespace BitmapGraphics
{
    //
    // file header: https://en.wikipedia.org/wiki/BMP_file_format#Bitmap_file_header
    // info header: https://en.wikipedia.org/wiki/BMP_file_format#DIB_header_(bitmap_information_header)
    //
    const Binary::Byte WindowsBitmapHeader::firstIdentifier{ 'B' };
    const Binary::Byte WindowsBitmapHeader::secondIdentifier{ 'M' };
    const Binary::DoubleWord WindowsBitmapHeader::reserved{ 0 };
    const Binary::DoubleWord WindowsBitmapHeader::rawImageOffset{ 14 + 40 }; // file header size + info header size

    WindowsBitmapHeader::WindowsBitmapHeader ( std::istream& is )
    {
        verifyEquality( firstIdentifier.getValue(), Binary::Byte::read( is ), "myFirstIdentifier" );
        verifyEquality( secondIdentifier.getValue(), Binary::Byte::read( is ), "mySecondIdentifier");
        myFileSize = Binary::DoubleWord::readLittleEndian( is );
        
    }
}
