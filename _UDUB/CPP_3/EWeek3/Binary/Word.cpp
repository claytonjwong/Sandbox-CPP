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
    Word Word::readProperEndian ( std::istream& is )
    {
        Byte first, second;
        read( is, first, second );
        
        if ( Binary::IS__LITTLE__ENDIAN() )
        {
            return Word{ second, first };
        }
        else
        {
            return Word{ first, second };
        }
    }
    
    Word Word::readLittleEndian ( std::istream& is )
    {
        Byte first, second;
        read( is, first, second );
        return Word{ second, first };
    }

    Word Word::readBigEndian ( std::istream& is )
    {
        Byte first, second;
        read( is, first, second );
        return Word{ first, second };
    }
    
    void Word::read ( std::istream& is, Byte& first, Byte& second )
    {
        first = Byte::read( is );
        if ( ! is )
        {
            throw std::runtime_error{ "unable to read Word's first byte from istream" };
        }

        second = Byte::read( is );
        if ( ! is )
        {
            throw std::runtime_error{ "unable to read Word's second byte from istream" };
        }
    }
    
    Word::Word ( WordType value ) :
    myValue{ value }
    {
    }
    
    Word::Word ( const Byte& first, const Byte& second )  :
    myValue{ 0 }
    {
        myValue =
            first.getValue()  << ( 1 * Byte::BIT_COUNT ) |
            second.getValue() << ( 0 * Byte::BIT_COUNT );
    }
    
    WordType Word::getValue() const noexcept
    {
        return myValue;
    }
    
    void Word::write ( std::ostream& os, bool forceBigEndian ) const
    {
        Binary::ByteType allBitsSet =
            static_cast<Binary::ByteType>(  (1 <<  ( Byte::BIT_COUNT + 1 ))  - 1  );
        Byte mask{ allBitsSet };
        Byte first =  ( myValue & mask << ( 1 * Byte::BIT_COUNT ) )  >> ( 1 * Byte::BIT_COUNT );
        Byte second = ( myValue & mask << ( 0 * Byte::BIT_COUNT ) )  >> ( 0 * Byte::BIT_COUNT );
    
        if ( !forceBigEndian && Binary::IS__LITTLE__ENDIAN() )
        {
            write( os, second, first );
        }
        else
        {
            write( os, first, second );
        }
    }
    
    void Word::writeLittleEndian ( std::ostream& os ) const
    {
        write( os );
    }
    
    void Word::writeBigEndian ( std::ostream& os ) const
    {
        write( os, true );
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
    
    std::ostream& operator<< ( std::ostream& os, const Word& rhs )
    {
        rhs.write( os );
        return os;
    }
}
