//
//  Word.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

/*

#include "Word.hpp"
#include "Common.hpp"
#include "binary_ostream_iterator.hpp"
#include <list>


namespace Binary
{
    Word Word::read ( std::istream& inStream, const Endianness&& forceEndian )
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
            std::reverse( bytes.begin(), bytes.end() );
        }
        
        return std::move(  Word{ bytes }  );
    }
    
    
    Word Word::readLittleEndian ( std::istream& inStream )
    {
        return std::move(  read( inStream, Endianness::Little )  );
    }


    Word Word::readBigEndian ( std::istream& inStream )
    {
        return std::move(  read( inStream, Endianness::Big )  );
    }
    
    
    void Word::read ( std::istream& inStream, std::list<Byte>& bytes )
    {
        for ( int index=0; index < Word::BYTE_COUNT; ++index )
        {
            auto byte = Byte::read( inStream );
            
            bytes.push_back( std::move( byte ) );
            
            if ( ! inStream )
            {
                throw std::runtime_error{ "unable to read Word byte from istream" };
            }
        }
    }
    
    
    Word::Word ( WordType value ) :
    myValue{ value }
    {
    }
    
    
    Word::Word ( const std::list<Byte>& bytes ) :
    myValue{ 0 }
    {
        int index = 0;
        for ( const auto& byte: bytes )
        {
            myValue |= ( byte.getValue() << ( index++ * Byte::BIT_COUNT ) );
        }
    }
    
    
    const WordType& Word::getValue() const noexcept
    {
        return myValue;
    }
    
    
    void Word::write ( std::ostream& outStream, const Binary::Endianness&& forceEndian ) const
    {        
        std::list<Byte> bytes;
        
        for ( int index = 0; index < Word::BYTE_COUNT; ++index)
        {
            Byte byte{ static_cast<ByteType>(
                (myValue & Byte::MASK_ALL_BITS_SET << ( index * Byte::BIT_COUNT ))  >> ( index * Byte::BIT_COUNT )  )  };
            
            bytes.emplace_back(  std::move( byte )  );
        }
    
        if (  ( forceEndian == Binary::Endianness::Little ) ||
              ( forceEndian == Binary::Endianness::Dynamic && Binary::IS__LITTLE__ENDIAN() )  )
        {
            ; // no-op, little endian by default
        }
        else
        {
            std::reverse( bytes.begin(), bytes.end() );
        }
        
        write( outStream, bytes );
    }
    
    
    void Word::writeLittleEndian ( std::ostream& outStream ) const
    {
        write( outStream, Binary::Endianness::Little );
    }
    
    
    void Word::writeBigEndian ( std::ostream& outStream ) const
    {
        write( outStream, Binary::Endianness::Big );
    }
    
    
    void Word::write( std::ostream& outStream, const std::list<Byte>& bytes )
    {
        std::copy( bytes.begin(), bytes.end(),
            Binary::binary_ostream_iterator<Byte>( outStream )  );
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
*/

