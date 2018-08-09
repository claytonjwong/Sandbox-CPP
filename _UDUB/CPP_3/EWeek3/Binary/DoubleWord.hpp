//
//  DoubleWord.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Byte.hpp"
#include <sstream>

namespace Binary
{
    using DoubleWordType = uint32_t;

    class DoubleWord
    {
    public:
        
        static DoubleWord readLittleEndian ( std::stringstream& ss );
        static DoubleWord readBigEndian ( std::stringstream& ss );
        
        DoubleWord();
        DoubleWord( DoubleWordType value );
        
        operator DoubleWordType();
        
    private:
    
        DoubleWordType myValue;
    };
}
