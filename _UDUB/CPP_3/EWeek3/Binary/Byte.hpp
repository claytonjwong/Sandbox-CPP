//
//  Byte.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/7/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include <sstream>

namespace Binary
{
    using ByteType=uint8_t;

    class Byte
    {
    public:
        
        static constexpr int BIT_COUNT = 8;
        
        static constexpr ByteType MASK_ALL_BITS_SET =
            static_cast<ByteType>(  ( 1 << ( Byte::BIT_COUNT + 1 ) )  - 1  );
        
        static Byte read ( std::istream& inStream );
        
        Byte() = default;
        ~Byte() = default;
        explicit Byte ( const ByteType& value );

        Byte ( const Byte& src ) = default;
        Byte ( Byte&& src ) = default;
        
        Byte& operator= ( const Byte& rhs ) = default;
        Byte& operator= ( Byte&& rhs ) = default;
        
        const ByteType& getValue() const noexcept;

        void write ( std::ostream& outStream ) const;

        operator ByteType() const noexcept;
        
        bool operator== ( const Byte& rhs ) const noexcept;
        
        template <typename Type>
        Byte& operator= ( Type&& rhs );

    private:
        
        ByteType myValue{ 0 };
        
    };
    
    template <typename Type>
    Byte& Byte::operator= ( Type&& rhs )
    {
        myValue = static_cast<ByteType>( rhs );
        return *this;
    }
    
    std::ostream& operator<< ( std::ostream& outStream, const Byte& rhs );
    
}

