//
//  WindowsBitmapHeader.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Common.hpp"
#include "Byte.hpp"
#include "Word.hpp"
#include "DoubleWord.hpp"
#include <iostream>

namespace BitmapGraphics
{

    class WindowsBitmapHeader
    {
    private:
            
        static const Binary::Byte myFirstIdentifier;
        static const Binary::Byte myFecondIdentifier;
        static const Binary::DoubleWord myReserved;
        static const Binary::DoubleWord myRawImageOffset;

    public:
    
        WindowsBitmapHeader ( std::istream& is )
        {
            verifyEquality( 1,1,"one" );
        }
        
    private:
    
        Binary::DoubleWord myFileSize;
    };
}
