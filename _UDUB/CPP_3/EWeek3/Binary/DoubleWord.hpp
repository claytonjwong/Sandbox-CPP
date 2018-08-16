//
//  DoubleWord.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Common.hpp"
#include "Byte.hpp"
#include <sstream>

namespace Binary
{
    using DoubleWordType = uint32_t;

    class DoubleWord
    {
    public:
        
        static constexpr int BYTE_COUNT = 4;
        
        static DoubleWord read ( std::istream& inStream, const Endianness&& forceEndian=Endianness::Dynamic );
        static DoubleWord readLittleEndian ( std::istream& inStream );
        static DoubleWord readBigEndian ( std::istream& inStream );
        
    private:
    
        static void read ( std::istream& inStream,
                           Byte& first, Byte& second,
                           Byte& third, Byte& fourth );
                           
    public:
    
        DoubleWord() = default;
        ~DoubleWord() = default;
        explicit DoubleWord ( DoubleWordType value );
        DoubleWord ( const Byte& first, const Byte& second,
                     const Byte& third, const Byte& fourth );
        
        DoubleWord ( const DoubleWord& src ) = default;
        DoubleWord ( DoubleWord&& src ) = default;
        
        DoubleWord& operator= ( const DoubleWord& rhs ) = default;
        DoubleWord& operator= ( DoubleWord&& rhs ) = default;

        DoubleWord& operator= ( const DoubleWordType& rhs );
        DoubleWord& operator= ( DoubleWordType&& rhs );

        const DoubleWordType& getValue() const noexcept;
        
        void write ( std::ostream& outStream, const Endianness&& forceEndian=Endianness::Dynamic ) const;
        void writeLittleEndian ( std::ostream& outStream ) const;
        void writeBigEndian ( std::ostream& outStream ) const;
    
    private:
    
        static void write ( std::ostream& outStream,
            const Byte& first, const Byte& second,
            const Byte& third, const Byte& fourth);
    
    public:
        
        operator DoubleWordType() const noexcept;
        
        bool operator== ( const DoubleWord& rhs ) const noexcept;
        
    private:
    
        DoubleWordType myValue{ 0 };
    };
    
    std::ostream& operator<< ( std::ostream& outStream, const DoubleWord& rhs );
}
