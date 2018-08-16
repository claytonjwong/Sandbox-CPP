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
    DoubleWord DoubleWord::read ( std::istream& is, const Endianness&& forceEndian )
    {
        Byte first, second, third, fourth;
        read ( is, first, second, third, fourth );
        
        if (  ( forceEndian == Binary::Endianness::Little ) ||
              ( forceEndian == Binary::Endianness::Dynamic && Binary::IS__LITTLE__ENDIAN() )  )
        {
            return std::move( DoubleWord{ fourth, third, second, first } );
        }
        else
        {
            return std::move( DoubleWord{ first, second, third, fourth } );
        }
    }

    DoubleWord DoubleWord::readLittleEndian ( std::istream& is )
    {
        return std::move(  read( is, Endianness::Little )  );
    }

    DoubleWord DoubleWord::readBigEndian ( std::istream& is )
    {
        return std::move(  read( is, Endianness::Big )  );
    }
    
    void DoubleWord::read ( std::istream& is,
                            Byte& first, Byte& second, Byte& third, Byte& fourth )
    {
        first = Byte::read( is );
        if ( ! is )
        {
            throw std::runtime_error{ "unable to read DoubleWord's first byte from istream" };
        }
        
        second = Byte::read( is );
        if ( ! is )
        {
            throw std::runtime_error{ "unable to read DoubleWord's second byte from istream" };
        }

        third = Byte::read( is );
        if ( ! is )
        {
            throw std::runtime_error{ "unable to read DoubleWord's third byte from istream" };
        }

        fourth = Byte::read( is );
        if ( ! is )
        {
            throw std::runtime_error{ "unable to read DoubleWord's fourth byte from istream" };
        }
    }
    
    DoubleWord::DoubleWord( DoubleWordType value ) :
    myValue{ value }
    {
    }
    
    DoubleWord::DoubleWord ( const Byte& first, const Byte& second,
                             const Byte& third, const Byte& fourth ) :
    myValue{ 0 }
    {
        myValue =
            first.getValue()  << ( 3 * Byte::BIT_COUNT ) |
            second.getValue() << ( 2 * Byte::BIT_COUNT ) |
            third.getValue()  << ( 1 * Byte::BIT_COUNT ) |
            fourth.getValue() << ( 0 * Byte::BIT_COUNT );
    }
    
    DoubleWord& DoubleWord::operator= ( const DoubleWordType& rhs )
    {
        myValue = rhs;
        return *this;
    }
    
    DoubleWord& DoubleWord::operator= ( DoubleWordType&& rhs )
    {
        myValue = rhs;
        return *this;
    }
    
    const DoubleWordType& DoubleWord::getValue() const noexcept
    {
        return myValue;
    }

    void DoubleWord::write ( std::ostream& os, const Endianness&& forceEndian ) const
    {
        Binary::ByteType mask =
            static_cast<ByteType>(  ( 1 << ( Byte::BIT_COUNT + 1 )) - 1  );
        
        Byte first{ static_cast<ByteType>(
            ( myValue & mask << ( 3 * Byte::BIT_COUNT ) )  >> ( 3 * Byte::BIT_COUNT )    ) };
        
        Byte second{ static_cast<ByteType>(
            ( myValue & mask << ( 2 * Byte::BIT_COUNT ) )  >> ( 2 * Byte::BIT_COUNT )    ) };
        
        Byte third{ static_cast<ByteType>(
            ( myValue & mask << ( 1 * Byte::BIT_COUNT ) )  >> ( 1 * Byte::BIT_COUNT )    ) };
        
        Byte fourth{ static_cast<ByteType>(
            ( myValue & mask << ( 0 * Byte::BIT_COUNT ) )  >> ( 0 * Byte::BIT_COUNT )    ) };

        if (  ( forceEndian == Binary::Endianness::Little ) ||
              ( forceEndian == Binary::Endianness::Dynamic && Binary::IS__LITTLE__ENDIAN() )  )
        {
            write( os, fourth, third, second, first );
        }
        else
        {
            write( os, first, second, third, fourth );
        }
    }
    
    void DoubleWord::writeLittleEndian ( std::ostream& os ) const
    {
        write( os, Endianness::Little );
    }
    
    void DoubleWord::writeBigEndian ( std::ostream& os ) const
    {
        write( os, Endianness::Big );
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
    
    std::ostream& operator<< ( std::ostream& os, const DoubleWord& rhs )
    {
        rhs.write( os );
        return os;
    }
}
