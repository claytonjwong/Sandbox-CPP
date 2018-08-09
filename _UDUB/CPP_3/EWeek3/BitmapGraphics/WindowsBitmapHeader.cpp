//
//  WindowsBitmapHeader.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "WindowsBitmapHeader.hpp"

namespace BitmapGraphics
{
    //
    // file header: https://en.wikipedia.org/wiki/BMP_file_format#Bitmap_file_header
    // info header: https://en.wikipedia.org/wiki/BMP_file_format#DIB_header_(bitmap_information_header)
    //
    static const Binary::Byte myFirstIdentifier{ 'B' };
    static const Binary::Byte mySecondIdentifier{ 'M' };
    static const Binary::DoubleWord myReserved{ 0 };
    static const Binary::DoubleWord myRawImageOffset{ 14 + 40 }; // file header size + info header size

}
