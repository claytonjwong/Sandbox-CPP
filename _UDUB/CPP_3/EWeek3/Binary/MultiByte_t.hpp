//
//  MultiByte_t.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/17/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Common.hpp"
#include "Byte.hpp"
#include "binary_ostream_iterator.hpp"
#include <sstream>
#include <list>

namespace Binary
{
    
    template <typename Type>
    class MultiByte_t
    {
    public:
        
        static constexpr int BYTE_COUNT {  sizeof( Type )  };
        
        static MultiByte_t read ( std::istream& inStream, const Endianness&& forceEndian = Endianness::Dynamic );
        static MultiByte_t readLittleEndian ( std::istream& inStream );
        static MultiByte_t readBigEndian ( std::istream& inStream );
        
        MultiByte_t() = default;
        ~MultiByte_t() = default;
        explicit MultiByte_t ( Type value );
        explicit MultiByte_t ( const std::list<Byte>& bytes );

        MultiByte_t ( const MultiByte_t& src ) = default;
        MultiByte_t ( MultiByte_t&& src ) = default;
        
        MultiByte_t& operator= ( const MultiByte_t& rhs ) = default;
        MultiByte_t& operator= ( MultiByte_t&& rhs ) = default;

        MultiByte_t& operator= ( const Type& rhs );
        MultiByte_t& operator= ( Type&& rhs );

        const Type& getValue() const noexcept;
        
        void write ( std::ostream& outStream, const Endianness&& forceEndian = Endianness::Dynamic ) const;
        void writeLittleEndian ( std::ostream& outStream ) const;
        void writeBigEndian ( std::ostream& outStream ) const;
        
        operator Type() const noexcept;
        
        bool operator== ( const MultiByte_t& rhs ) const noexcept;
        
    private:
    
        Type myValue{ 0 };
        
        static void read ( std::istream& inStream, std::list<Byte>& bytes );
        static void write ( std::ostream& outStream, const std::list<Byte>& bytes );
    };
    
    
    template <typename Type>
    MultiByte_t<Type> MultiByte_t<Type>::read ( std::istream& inStream, const Endianness&& forceEndian )
    {
        std::list<Byte> bytes;
        
        read( inStream, bytes );
        
        if (  ( forceEndian == Endianness::Little ) ||
              ( forceEndian == Endianness::Dynamic && SYSTEM_ENDIANNESSS() == Endianness::Little )  )
        {
            ; // no-op, little endian by default
        }
        else
        {
            reverse( bytes.begin(), bytes.end() );
        }
        
        return std::move(  MultiByte_t<Type>{ bytes }  );
    }
    
    
    template <typename Type>
    MultiByte_t<Type> MultiByte_t<Type>::readLittleEndian ( std::istream& inStream )
    {
        return std::move(  read( inStream, Endianness::Little )  );
    }
    

    template <typename Type>
    MultiByte_t<Type> MultiByte_t<Type>::readBigEndian ( std::istream& inStream )
    {
        return std::move(  read( inStream, Endianness::Big )  );
    }
    
    
    template <typename Type>
    MultiByte_t<Type>::MultiByte_t ( Type value ) :
    myValue{ value }
    {
    }
    
    
    template <typename Type>
    MultiByte_t<Type>::MultiByte_t ( const std::list<Byte>& bytes ) :
    myValue{ 0 }
    {
        int index = 0;
        for ( const auto& byte: bytes )
        {
            myValue |= ( byte.getValue() << ( index++ * Byte::BIT_COUNT ) );
        }
    }
    
    
    template <typename Type>
    MultiByte_t<Type>& MultiByte_t<Type>::operator= ( const Type& rhs )
    {
        myValue = static_cast<Type>( rhs );
        return *this;
    }


    template <typename Type>
    MultiByte_t<Type>& MultiByte_t<Type>::operator= ( Type&& rhs )
    {
        myValue = static_cast<Type>( rhs );
        return *this;
    }
    
    
    template <typename Type>
    const Type& MultiByte_t<Type>::getValue() const noexcept
    {
        return myValue;
    }
    

    template <typename Type>
    void MultiByte_t<Type>::write ( std::ostream& outStream, const Endianness&& forceEndian ) const
    {
        static std::list<Byte> bytes;
        bytes.clear();
        
        for ( int index = 0; index < MultiByte_t<Type>::BYTE_COUNT; ++index )
        {
            Byte byte{ static_cast<ByteType>(
                ( myValue & Byte::MASK_ALL_BITS_SET << ( index * Byte::BIT_COUNT ) )
                    >> ( index * Byte::BIT_COUNT )    ) };
            
            bytes.emplace_back(  std::move( byte )  );
        }

        if ( ! (  ( forceEndian == Endianness::Little ) ||
              ( forceEndian == Endianness::Dynamic && SYSTEM_ENDIANNESSS() == Endianness::Little )  ) )
        {
            reverse( bytes.begin(), bytes.end() );
        }
        
        write( outStream, bytes );
    }
    
    
    template <typename Type>
    void MultiByte_t<Type>::writeLittleEndian ( std::ostream& outStream ) const
    {
        write( outStream, Endianness::Little );
    }
    
    
    template <typename Type>
    void MultiByte_t<Type>::writeBigEndian ( std::ostream& outStream ) const
    {
        write( outStream, Endianness::Big );
    }
    
    
    template <typename Type>
    MultiByte_t<Type>::operator Type() const noexcept
    {
        return myValue;
    }


    template <typename Type>
    bool MultiByte_t<Type>::operator== ( const MultiByte_t<Type>& rhs ) const noexcept
    {
        return myValue == rhs.myValue;
    }
    
    
    template <typename Type>
    std::ostream& operator<< ( std::ostream& outStream, const MultiByte_t<Type>& rhs )
    {
        rhs.write( outStream );
        
        return outStream;
    }
    

    template <typename Type>
    void MultiByte_t<Type>::read ( std::istream& inStream, std::list<Byte>& bytes )
    {
        for ( int index = 0; index < MultiByte_t<Type>::BYTE_COUNT; ++index )
        {
            auto byte = Byte::read( inStream );
            
            bytes.emplace_back(  std::move( byte )  );
            
            if ( ! inStream )
            {
                throw std::runtime_error{ "unable to read DoubleWord from istream" };
            }
        }
    }


    template <typename Type>
    void MultiByte_t<Type>::write ( std::ostream& outStream, const std::list<Byte>& bytes )
    {
        std::copy( bytes.begin(), bytes.end(), binary_ostream_iterator<Byte>( outStream )  );
    }

}
