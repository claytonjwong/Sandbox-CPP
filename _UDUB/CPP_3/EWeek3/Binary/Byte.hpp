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
        
        static Byte read ( std::istream& is ) noexcept;
        
        Byte() = default;
        ~Byte() = default;
        explicit Byte ( ByteType value );

        Byte ( const Byte& src ) = default;
        Byte ( Byte&& src ) = default;
        
        Byte& operator= ( const Byte& rhs ) = default;
        Byte& operator= ( Byte&& rhs ) = default;
        
        Byte& operator= ( const ByteType& rhs );
        Byte& operator= ( ByteType&& rhs );
        
        const ByteType& getValue() const noexcept;

        void write ( std::ostream& os ) const;
        
        operator ByteType() const noexcept; // should be explicit?  I'm not sure how to get that to compile though
        
        bool operator== ( const Byte& rhs ) const noexcept;
        
    private:
        
        ByteType myValue{ 0 };
        
    };
    
    std::ostream& operator<< ( std::ostream& os, const Byte& rhs );
    
}
