//
//  Word.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Word.hpp"
#include "Common.hpp"

namespace Binary
{
    Word Word::readLittleEndian ( std::istream& is )
    {
        auto first = Byte::read( is );
        auto second = Byte::read( is );
//
// question: which is preferrable?  "magic" numbers below was easier to write,
// but maybe calculating the size here is more idiomatic self-documenting code?
//
        return Word{
            static_cast<Word>(
                first  << ( 0 * Byte::BIT_COUNT ) |
                second << ( 1 * Byte::BIT_COUNT )
            )
        };
//
// "magic" numbers...
//

//        return Word{
//            static_cast<WordType>( first | second << 8 )
//        };
    }

    Word Word::readBigEndian ( std::istream& is )
    {
        auto first = Byte::read( is );
        auto second = Byte::read( is );
//
// question: which is preferrable?  "magic" numbers below was easier to write,
// but maybe calculating the size here is more idiomatic self-documenting code?
//
        return Word{
            static_cast<Word>(
                first  << ( 1 * Byte::BIT_COUNT ) |
                second << ( 0 * Byte::BIT_COUNT )
            )
        };
//
// "magic" numbers...
//

//        return Word{
//            static_cast<WordType>( first << 8 | second )
//        };
    }

    Word::Word ( WordType value ) :
    myValue{ value }
    {
    }
    
    WordType Word::getValue() const noexcept
    {
        return myValue;
    }
    
    void Word::write ( std::ostream& os ) const
    {
        Byte first =  ( myValue & 0xFF00 ) >> 8;
        Byte second = ( myValue & 0x00FF ) >> 0;
    
        if ( Binary::IS__LITTLE__ENDIAN() )
        {
            write( os, second, first );
        }
        else
        {
            write( os, first, second );
        }
    }
    
    void Word::write( std::ostream& os, const Byte& first, const Byte& second )
    {
        first.write( os );
        if ( ! os )
        {
            throw std::runtime_error{ "unable to write Word's first byte to ostream" };
        }
        second.write( os );
        if ( ! os )
        {
            throw std::runtime_error{ "unable to write Word's second byte to ostream" };
        }

    }

    Word::operator WordType() const noexcept
    {
        return myValue;
    }
    
    bool Word::operator== ( const Word& rhs ) const noexcept
    {
        return myValue == rhs.myValue;
    }
}
