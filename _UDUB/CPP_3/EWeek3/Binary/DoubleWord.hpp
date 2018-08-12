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
        
        static constexpr int BYTE_COUNT = 4;
        
        static DoubleWord readAnyEndian ( std::istream& is );
        static DoubleWord readLittleEndian ( std::istream& is );
        static DoubleWord readBigEndian ( std::istream& is );
        
    private:
    
        static void read ( std::istream& is,
                           Byte& first, Byte& second,
                           Byte& third, Byte& fourth );
                           
    public:
    
        DoubleWord() = default;
        DoubleWord ( DoubleWordType value );
        DoubleWord ( const Byte& first, const Byte& second,
                     const Byte& third, const Byte& fourth );
        
        DoubleWord ( const DoubleWord& src ) = default;
        DoubleWord ( DoubleWord&& src ) = default;
        
        DoubleWord& operator= ( const DoubleWord& rhs ) = default;
        DoubleWord& operator= ( DoubleWord&& rhs ) = default;
        
        DoubleWordType getValue() const noexcept;
        
        void write ( std::ostream& os ) const;
    
    private:
    
        static void write ( std::ostream& os,
            const Byte& first, const Byte& second, const Byte& third, const Byte& fourth);
    
    public:
    
        operator DoubleWordType() const noexcept;
        bool operator== ( const DoubleWord& rhs ) const noexcept;
        
    private:
    
        DoubleWordType myValue{ 0 };
    };
}
