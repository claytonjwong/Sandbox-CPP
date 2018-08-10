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
    using WordType = uint16_t;
    
    class Word
    {
    public:
    
        static Word readLittleEndian ( std::istream& ss );
        static Word readBigEndian ( std::istream& ss );

        Word() = delete;
        Word ( WordType value );
        
        Word ( const Word& src ) = default;
        Word ( Word&& src ) = default;
        
        Word& operator= ( const Word& rhs ) = default;
        Word& operator= ( Word&& rhs ) = default;
        
        WordType getValue() const noexcept;
        
        operator WordType() const noexcept;
        
        bool operator== ( const Word& rhs ) const noexcept;
        
    private:
    
        WordType myValue;
    };
}
