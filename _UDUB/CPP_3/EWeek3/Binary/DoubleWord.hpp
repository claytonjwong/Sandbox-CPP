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
        
        static DoubleWord readLittleEndian ( std::istream& ss );
        static DoubleWord readBigEndian ( std::istream& ss );
        
        DoubleWord() = default;
        DoubleWord ( DoubleWordType value );
        
        DoubleWord ( const DoubleWord& src ) = default;
        DoubleWord ( DoubleWord&& src ) = default;
        
        DoubleWord& operator= ( const DoubleWord& rhs ) = default;
        DoubleWord& operator= ( DoubleWord&& rhs ) = default;
        
        operator DoubleWordType();
        
        DoubleWordType getValue() const noexcept;
        
        bool operator== ( const DoubleWord& rhs ) const noexcept;
        
    private:
    
        DoubleWordType myValue{ 0 };
    };
}
