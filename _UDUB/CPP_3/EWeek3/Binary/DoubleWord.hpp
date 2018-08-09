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
        
        static DoubleWord readLittleEndian ( std::stringstream& ss )
        {
            auto first = Byte::read( ss );
            auto second = Byte::read( ss );
            auto third = Byte::read( ss );
            auto fourth = Byte::read( ss );
            return DoubleWord{ static_cast<DoubleWord>( first | second << 8 | third << 16 | fourth << 24 ) };
        }
        
        static DoubleWord readBigEndian ( std::stringstream& ss )
        {
            auto first = Byte::read( ss );
            auto second = Byte::read( ss );
            auto third = Byte::read( ss );
            auto fourth = Byte::read( ss );
            return DoubleWord{ static_cast<DoubleWord>( first << 24 | second << 16 | third << 8 | fourth ) };
        }
        
        DoubleWord() :
        myValue{ 0 }
        {
        }
        
        DoubleWord( DoubleWordType value ) :
        myValue{ value }
        {
        }
        
        operator DoubleWordType()
        {
            return myValue;
        }
        
    private:
    
        DoubleWordType myValue;
    };
}
