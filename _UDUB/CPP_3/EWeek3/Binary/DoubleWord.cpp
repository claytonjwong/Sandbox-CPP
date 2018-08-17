//
//  DoubleWord.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "DoubleWord.hpp"
#include "Common.hpp"
#include <list>

namespace Binary
{
    DoubleWord DoubleWord::read ( std::istream& inStream, const Endianness&& forceEndian )
    {
        std::list<Byte> bytes;
        
        read( inStream, bytes );
        
        if (  ( forceEndian == Binary::Endianness::Little ) ||
              ( forceEndian == Binary::Endianness::Dynamic && Binary::IS__LITTLE__ENDIAN() )  )
        {
            ; // no-op, little endian by default
        }
        else
        {
            reverse( bytes.begin(), bytes.end() );
        }
        
        return std::move( DoubleWord{ bytes } );
    }
    
    void DoubleWord::read ( std::istream& inStream, std::list<Byte>& bytes )
    {
        for ( int index = 0; index < DoubleWord::BYTE_COUNT; ++index )
        {
            Byte byte = Byte::read( inStream );
            
            bytes.push_back(  std::move( byte )  );
            
            if ( ! inStream )
            {
                throw std::runtime_error{ "unable to read DoubleWord from istream" };
            }
        }
    }

    DoubleWord DoubleWord::readLittleEndian ( std::istream& inStream )
    {
        return std::move(  read( inStream, Endianness::Little )  );
    }

    DoubleWord DoubleWord::readBigEndian ( std::istream& inStream )
    {
        return std::move(  read( inStream, Endianness::Big )  );
    }
    
    DoubleWord::DoubleWord( DoubleWordType value ) :
    myValue{ value }
    {
    }
    
    DoubleWord::DoubleWord ( const std::list<Byte>& bytes ) :
    myValue{ 0 }
    {
        int index = 0;
        for ( const auto& byte: bytes )
        {
            myValue |= ( byte.getValue() << ( index++ * Byte::BIT_COUNT ) );
        }
    }
    
    DoubleWord& DoubleWord::operator= ( const DoubleWordType& rhs )
    {
        myValue = rhs;
        return *this;
    }
    
    DoubleWord& DoubleWord::operator= ( DoubleWordType&& rhs )
    {
        myValue = std::move( rhs );
        return *this;
    }
    
    const DoubleWordType& DoubleWord::getValue() const noexcept
    {
        return myValue;
    }

    void DoubleWord::write ( std::ostream& outStream, const Endianness&& forceEndian ) const
    {
        std::list<Byte> bytes;
        
        for ( int index = 0; index < DoubleWord::BYTE_COUNT; ++index )
        {
            Byte byte{ static_cast<ByteType>(
                (myValue & Byte::MASK_ALL_BITS_SET << ( index * Byte::BIT_COUNT ))  >> ( index * Byte::BIT_COUNT )  )  };
            bytes.push_back(  std::move( byte )  );
        }

        if (  ( forceEndian == Binary::Endianness::Little ) ||
              ( forceEndian == Binary::Endianness::Dynamic && Binary::IS__LITTLE__ENDIAN() )  )
        {
            ; // no-op, little endian by default
        }
        else
        {
            reverse( bytes.begin(), bytes.end() );
        }
        
        write( outStream, bytes );
    }
    
    void DoubleWord::writeLittleEndian ( std::ostream& outStream ) const
    {
        write( outStream, Endianness::Little );
    }
    
    void DoubleWord::writeBigEndian ( std::ostream& outStream ) const
    {
        write( outStream, Endianness::Big );
    }
    
    void DoubleWord::write ( std::ostream& outStream, const std::list<Byte>& bytes )
    {
        for ( const auto& byte: bytes )
        {
            byte.write( outStream );
            
            if ( ! outStream )
            {
                throw std::runtime_error{ "unable to write DoubleWord byte to ostream" };
            }
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
    
    std::ostream& operator<< ( std::ostream& outStream, const DoubleWord& rhs )
    {
        rhs.write( outStream );
        return outStream;
    }
}
