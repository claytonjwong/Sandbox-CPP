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
            
        static const Binary::Byte firstIdentifier;
        static const Binary::Byte secondIdentifier;
        static const Binary::DoubleWord reserved;
        static const Binary::DoubleWord rawImageOffset;

    public:
    
        WindowsBitmapHeader ( std::istream& is );
        
    private:
    
        Binary::DoubleWord myFileSize;
    };
}
