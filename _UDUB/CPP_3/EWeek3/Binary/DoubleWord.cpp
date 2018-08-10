//
//  DoubleWord.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "DoubleWord.hpp"
#include "Common.hpp"

namespace Binary
{
    DoubleWord DoubleWord::readLittleEndian ( std::istream& is )
    {
        auto first  = Byte::read( is );
        auto second = Byte::read( is );
        auto third  = Byte::read( is );
        auto fourth = Byte::read( is );
//
// question: which is preferrable?  "magic" numbers below was easier to write,
// but maybe calculating the size here is more idiomatic self-documenting code?
//
        return DoubleWord{
            static_cast<DoubleWord>(
                first  << ( 0 * Byte::BIT_COUNT ) |
                second << ( 1 * Byte::BIT_COUNT ) |
                third  << ( 2 * Byte::BIT_COUNT ) |
                fourth << ( 3 * Byte::BIT_COUNT )
            )
        };
//
// "magic" numbers...
//

//        return DoubleWord{
//            static_cast<DoubleWord>( first | second << 8 | third << 16 | fourth << 24 )
//        };
    }

    DoubleWord DoubleWord::readBigEndian ( std::istream& is )
    {
        auto first  = Byte::read( is );
        auto second = Byte::read( is );
        auto third  = Byte::read( is );
        auto fourth = Byte::read( is );
//
// question: which is preferrable?  "magic" numbers below was easier to write,
// but maybe below is more dynamic, flexible, idiomatic self-documenting code?
//
        return DoubleWord{
            static_cast<DoubleWord>(
                first  << ( 3 * Byte::BIT_COUNT ) |
                second << ( 2 * Byte::BIT_COUNT ) |
                third  << ( 1 * Byte::BIT_COUNT ) |
                fourth << ( 0 * Byte::BIT_COUNT )
            )
        };
//
// "magic" numbers...
//

//        return DoubleWord{
//            static_cast<DoubleWord>( first << 24 | second << 16 | third << 8 | fourth )
//        };
    }

    DoubleWord::DoubleWord( DoubleWordType value ) :
    myValue{ value }
    {
    }
    
    DoubleWordType DoubleWord::getValue() const noexcept
    {
        return myValue;
    }

    void DoubleWord::write ( std::ostream& os ) const
    {
//
// question: which is preferrable?  "magic" numbers below was easier to write,
// but maybe below is more dynamic, flexible, idiomatic self-documenting code?
//
        Binary::ByteType allBitsSet = static_cast<Binary::ByteType>(  1 <<  ( Byte::BIT_COUNT + 1 )  ) - 1;
        Byte mask{ allBitsSet };
        Byte first =  ( myValue & mask << ( 3 * Byte::BIT_COUNT ) )  >> ( 3 * Byte::BIT_COUNT );
        Byte second = ( myValue & mask << ( 2 * Byte::BIT_COUNT ) )  >> ( 2 * Byte::BIT_COUNT );
        Byte third =  ( myValue & mask << ( 1 * Byte::BIT_COUNT ) )  >> ( 1 * Byte::BIT_COUNT );
        Byte fourth = ( myValue & mask << ( 0 * Byte::BIT_COUNT ) )  >> ( 0 * Byte::BIT_COUNT );
//
// "magic" numbers...
//

//        Byte first =  ( myValue & 0xFF000000 ) >> 24;
//        Byte second = ( myValue & 0x00FF0000 ) >> 16;
//        Byte third =  ( myValue & 0x0000FF00 ) >> 8;
//        Byte fourth = ( myValue & 0x000000FF );

        if ( IS__LITTLE__ENDIAN() )
        {
            write( os, fourth, third, second, first );
        }
        else
        {
            write( os, first, second, third, fourth );
        }
    }
    
    void DoubleWord::write ( std::ostream& os,
        const Byte& first, const Byte& second, const Byte& third, const Byte& fourth)
    {
        first.write( os );
        if ( ! os )
        {
            throw std::runtime_error{ "unable to write DoubleWord's first byte to ostream" };
        }
        second.write( os );
        if ( ! os )
        {
            throw std::runtime_error{ "unable to write DoubleWord's second byte to ostream" };
        }
        third.write( os );
        if ( ! os )
        {
            throw std::runtime_error{ "unable to write DoubleWord's second byte to ostream" };
        }
        fourth.write( os );
        if ( ! os )
        {
            throw std::runtime_error{ "unable to write DoubleWord's second byte to ostream" };
        }
    }

    DoubleWord::operator DoubleWordType() const noexcept
    {
        return myValue;
    }

    bool DoubleWord::operator== ( const DoubleWord& rhs ) const noexcept
    {
        return myValue == rhs.myValue;
    }
}
