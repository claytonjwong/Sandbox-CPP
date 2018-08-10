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
        auto bitsPerByte = Byte::BITS * sizeof( ByteType );
        return DoubleWord{
            static_cast<DoubleWord>(
                first  << ( 0 * bitsPerByte ) |
                second << ( 1 * bitsPerByte ) |
                third  << ( 2 * bitsPerByte ) |
                fourth << ( 3 * bitsPerByte )
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
// but maybe calculating the size here is more idiomatic self-documenting code?
//
        auto bitsPerByte = Byte::BITS * sizeof( ByteType );
        return DoubleWord{
            static_cast<DoubleWord>(
                first  << ( 3 * bitsPerByte ) |
                second << ( 2 * bitsPerByte ) |
                third  << ( 1 * bitsPerByte ) |
                fourth << ( 0 * bitsPerByte )
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
        Byte first =  ( myValue & 0xFF000000 ) >> ( 8 * 3 );
        Byte second = ( myValue & 0x00FF0000 ) >> ( 8 * 2 );
        Byte third =  ( myValue & 0x0000FF00 ) >> ( 8 * 1 );
        Byte fourth = ( myValue & 0x000000FF ) >> ( 8 * 0 );
        
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
