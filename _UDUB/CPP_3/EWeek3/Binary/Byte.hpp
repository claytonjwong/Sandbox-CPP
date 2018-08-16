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
        
        static Byte read ( std::istream& inStream ) noexcept;
        
        Byte() = default;
        ~Byte() = default;
        explicit Byte ( const ByteType& value );

        Byte ( const Byte& src ) = default;
        Byte ( Byte&& src ) = default;
        
        Byte& operator= ( const Byte& rhs ) = default;
        Byte& operator= ( Byte&& rhs ) = default;
        
        Byte& operator= ( const ByteType& rhs );
        Byte& operator= ( ByteType&& rhs );
        
        const ByteType& getValue() const noexcept;

        void write ( std::ostream& outStream ) const;

        //
        // operator ByteType() const noexcept;
        //
        // should be explicit?  I'm not sure how to get that to compile though
        //
        // I get a compiler error when I make this operator explicit:
        //
        // explicit operator ByteType() const noexcept;
        //
        // maybe the test case is out-of-date?...
        //
        //    unsigned char c3{};
        //    c3 = byte2;
        //
        // Assigning to 'unsigned char' from incompatible type 'Binary::Byte'
        //
        // This can be resolved by either:
        //
        // 1) removing "explicit" in the Byte class, then the test case remains unchanged
        //
        //    unsigned char c3{};
        //    c3 = byte2;
        //
        // OR
        //
        // 2) modifying the test case to explicitly cast the byte to an unsigned char
        //
        //    unsigned char c3{};
        //    c3 = static_cast<Binary::ByteType>(byte2);
        //
        // since multiple test cases would need to be modified for #2,
        // I choose #1 to resolve this issue
        //
        // there is a good possibility that I have completely misunderstood this operator usage
        // my understanding is that when this is marked as "explicit", then the test case
        // must explicitly perform static_cast to change byte2 to an unsigned char.  However, since
        // I removed explicit, the test case is allowed to implicitly perform this conversion
        // without having to modify the test case by adding a static_cast
        //
        operator ByteType() const noexcept;
        
        bool operator== ( const Byte& rhs ) const noexcept;
        
    private:
        
        ByteType myValue{ 0 };
        
    };
    
    std::ostream& operator<< ( std::ostream& outStream, const Byte& rhs );
    
}
