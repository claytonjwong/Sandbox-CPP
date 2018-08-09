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
        
        static Word readLittleEndian ( std::stringstream& ss )
        {
            auto first = Byte::read( ss );
            auto second = Byte::read( ss );
            return Word{  static_cast<WordType>( first | second << 8 )  };
        }

        static Word readBigEndian ( std::stringstream& ss )
        {
            auto first = Byte::read( ss );
            auto second = Byte::read( ss );
            return Word{  static_cast<WordType>( first << 8 | second )  };
        }

        Word ( WordType value ) :
        myValue{ value }
        {
        }
        
        operator WordType()
        {
            return myValue;
        }
        
    private:
    
        WordType myValue;
    };
}
