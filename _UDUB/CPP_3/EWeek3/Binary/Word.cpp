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
    Word Word::read ( std::istream& inStream, const Endianness&& forceEndian )
    {
        Byte first, second;
        read( inStream, first, second );
        
        if (  ( forceEndian == Binary::Endianness::Little ) ||
              ( forceEndian == Binary::Endianness::Dynamic && Binary::IS__LITTLE__ENDIAN() )  )
        {
            return std::move( Word{ second, first } );
        }
        else
        {
            return std::move( Word{ first, second } );
        }
    }
    
    Word Word::readLittleEndian ( std::istream& inStream )
    {
        return std::move(  read( inStream, Endianness::Little )  );
    }

    Word Word::readBigEndian ( std::istream& inStream )
    {
        return std::move(  read( inStream, Endianness::Big )  );
    }
    
    void Word::read ( std::istream& inStream, Byte& first, Byte& second )
    {
        first = Byte::read( inStream );
        if ( ! inStream )
        {
            throw std::runtime_error{ "unable to read Word's first byte from istream" };
        }

        second = Byte::read( inStream );
        if ( ! inStream )
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
    
    const WordType& Word::getValue() const noexcept
    {
        return myValue;
    }
    
    void Word::write ( std::ostream& outStream, const Binary::Endianness&& forceEndian ) const
    {
        ByteType mask =
            static_cast<ByteType>(  (1 <<  ( Byte::BIT_COUNT + 1 ))  - 1  );
        
        Byte first{ static_cast<ByteType>(
            ( myValue & mask << ( 1 * Byte::BIT_COUNT ) )  >> ( 1 * Byte::BIT_COUNT )    ) };
            
        Byte second{ static_cast<ByteType>(
            ( myValue & mask << ( 0 * Byte::BIT_COUNT ) )  >> ( 0 * Byte::BIT_COUNT )    ) };
    
        if (  ( forceEndian == Binary::Endianness::Little ) ||
              ( forceEndian == Binary::Endianness::Dynamic && Binary::IS__LITTLE__ENDIAN() )  )
        {
            write( outStream, second, first );
        }
        else
        {
            write( outStream, first, second );
        }
    }
    
    void Word::writeLittleEndian ( std::ostream& outStream ) const
    {
        write( outStream, Binary::Endianness::Little );
    }
    
    void Word::writeBigEndian ( std::ostream& outStream ) const
    {
        write( outStream, Binary::Endianness::Big );
    }
    
    void Word::write( std::ostream& outStream, const Byte& first, const Byte& second )
    {
        first.write( outStream );
        if ( ! outStream )
        {
            throw std::runtime_error{ "unable to write Word's first byte to ostream" };
        }
        second.write( outStream );
        if ( ! outStream )
        {
            throw std::runtime_error{ "unable to write Word's second byte to ostream" };
        }
    }

    Word& Word::operator= ( const WordType& rhs )
    {
        myValue = rhs;
        return *this;
    }
    
    Word& Word::operator= ( WordType&& rhs )
    {
        myValue = std::move( rhs );
        return *this;
    }

    Word::operator WordType() const noexcept
    {
        return myValue;
    }
    
    bool Word::operator== ( const Word& rhs ) const noexcept
    {
        return myValue == rhs.myValue;
    }
    
    std::ostream& operator<< ( std::ostream& outStream, const Word& rhs )
    {
        rhs.write( outStream );
        return outStream;
    }
}
