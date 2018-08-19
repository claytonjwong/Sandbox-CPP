//
//  Binary_t.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/19/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Common.hpp"
#include "Byte.hpp"
#include "binary_ostream_iterator.hpp"
#include <sstream>
#include <vector>

namespace Binary
{
    
    template <typename Type>
    class Binary_t
    {
    public:
        
        static constexpr int BYTE_COUNT {  sizeof( Type )  };
        
        static Binary_t read ( std::istream& inStream, const Endianness&& forceEndian = Endianness::Dynamic );
        static Binary_t readLittleEndian ( std::istream& inStream );
        static Binary_t readBigEndian ( std::istream& inStream );
        
        Binary_t() = default;
        ~Binary_t() = default;
        explicit Binary_t ( Type value );

        Binary_t ( const Binary_t& src ) = default;
        Binary_t ( Binary_t&& src ) = default;
        
        Binary_t& operator= ( const Binary_t& rhs ) = default;
        Binary_t& operator= ( Binary_t&& rhs ) = default;

        Binary_t& operator= ( const Type& rhs );
        Binary_t& operator= ( Type&& rhs );

        const Type& getValue() const noexcept;
        
        void write ( std::ostream& outStream, const Endianness&& forceEndian = Endianness::Dynamic ) const;
        void writeLittleEndian ( std::ostream& outStream ) const;
        void writeBigEndian ( std::ostream& outStream ) const;
        
        operator Type() const noexcept;
        
        bool operator== ( const Binary_t& rhs ) const noexcept;
        
    private:
    
        Type myValue{ 0 };
    
    };
    
    
    template <typename Type>
    Binary_t<Type> Binary_t<Type>::read ( std::istream& inStream, const Endianness&& forceEndian )
    {
        Type readResult{ 0 };
        auto mask{ Byte::MASK_ALL_BITS_SET };
        auto bits{ Byte::BIT_COUNT };
        int shift{ 0 };

        for ( int index = 0; index < Binary_t<Type>::BYTE_COUNT; ++index )
        {
            char buffer;
            inStream.get( buffer );
            auto byteValue = static_cast<ByteType>( buffer );

            if ( ! inStream )
            {
                throw std::runtime_error{ "unable to read DoubleWord from istream" };
            }

            if (  ( forceEndian == Endianness::Little ) ||
                  ( forceEndian == Endianness::Dynamic && SYSTEM_ENDIANNESSS() == Endianness::Little )  )
            {
                shift = index * bits;
            }
            else
            {
                shift = ( Binary_t<Type>::BYTE_COUNT - 1 - index ) * bits;
            }
            
            readResult |= byteValue << shift;
        }

        return std::move(  Binary_t<Type>{ readResult }  );
    }
    
    
    template <typename Type>
    Binary_t<Type> Binary_t<Type>::readLittleEndian ( std::istream& inStream )
    {
        return std::move(  read( inStream, Endianness::Little )  );
    }
    

    template <typename Type>
    Binary_t<Type> Binary_t<Type>::readBigEndian ( std::istream& inStream )
    {
        return std::move(  read( inStream, Endianness::Big )  );
    }
    
    
    template <typename Type>
    Binary_t<Type>::Binary_t ( Type value ) :
    myValue{ value }
    {
    }
    
    
    template <typename Type>
    Binary_t<Type>& Binary_t<Type>::operator= ( const Type& value )
    {
        myValue = static_cast<Type>( value );
        return *this;
    }


    template <typename Type>
    Binary_t<Type>& Binary_t<Type>::operator= ( Type&& rhs )
    {
        myValue = static_cast<Type>( rhs );
        return *this;
    }
    
    
    template <typename Type>
    const Type& Binary_t<Type>::getValue() const noexcept
    {
        return myValue;
    }
    

    template <typename Type>
    void Binary_t<Type>::write ( std::ostream& outStream, const Endianness&& forceEndian ) const
    {
        auto mask = Byte::MASK_ALL_BITS_SET;
        auto bits = Byte::BIT_COUNT;
        int shift{ 0 };
    
        for ( int index = 0; index < Binary_t<Type>::BYTE_COUNT; ++index )
        {
            if (  ( forceEndian == Endianness::Little ) ||
                  ( forceEndian == Endianness::Dynamic && SYSTEM_ENDIANNESSS() == Endianness::Little ) )
            {
                shift = index * bits;
            }
            else
            {
                shift = ( Binary_t<Type>::BYTE_COUNT - 1 - index ) * bits;
            }
            
            ByteType value = ( myValue & mask << shift ) >> shift;
            outStream << value;
        }
    }
    
    
    template <typename Type>
    void Binary_t<Type>::writeLittleEndian ( std::ostream& outStream ) const
    {
        write( outStream, Endianness::Little );
    }
    
    
    template <typename Type>
    void Binary_t<Type>::writeBigEndian ( std::ostream& outStream ) const
    {
        write( outStream, Endianness::Big );
    }
    
    
    template <typename Type>
    Binary_t<Type>::operator Type() const noexcept
    {
        return myValue;
    }


    template <typename Type>
    bool Binary_t<Type>::operator== ( const Binary_t<Type>& rhs ) const noexcept
    {
        return myValue == rhs.myValue;
    }
    
    
    template <typename Type>
    std::ostream& operator<< ( std::ostream& outStream, const Binary_t<Type>& rhs )
    {
        rhs.write( outStream );
        
        return outStream;
    }
    

}
