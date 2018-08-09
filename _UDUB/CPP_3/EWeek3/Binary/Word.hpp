//
//  Word.hpp
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
    class Word
    {
    public:
    
        using WordType = uint16_t;
        
        static Word readLittleEndian ( std::stringstream& ss );
        static Word readBigEndian ( std::stringstream& ss );

        Word ( WordType value );
        
        operator WordType();
        
    private:
    
        WordType myValue;
    };
}
