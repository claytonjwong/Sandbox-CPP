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
#include <list>

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
        
        static void read ( std::istream& inStream, std::list<Byte>& bytes );

    public:
    
        DoubleWord() = default;
        ~DoubleWord() = default;
        explicit DoubleWord ( DoubleWordType value );
        explicit DoubleWord ( const std::list<Byte>& bytes );

        DoubleWord ( const DoubleWord& src ) = default;
        DoubleWord ( DoubleWord&& src ) = default;
        
        DoubleWord& operator= ( const DoubleWord& rhs ) = default;
        DoubleWord& operator= ( DoubleWord&& rhs ) = default;

        template <typename Type>
        DoubleWord& operator= ( Type&& rhs );

        const DoubleWordType& getValue() const noexcept;
        
        void write ( std::ostream& outStream, const Endianness&& forceEndian=Endianness::Dynamic ) const;
        void writeLittleEndian ( std::ostream& outStream ) const;
        void writeBigEndian ( std::ostream& outStream ) const;
    
    private:
        
        static void write ( std::ostream& outStream, const std::list<Byte>& bytes );
    
    public:
        
        operator DoubleWordType() const noexcept;
        
        bool operator== ( const DoubleWord& rhs ) const noexcept;
        
    private:
    
        DoubleWordType myValue{ 0 };
    };

    template <typename Type>
    DoubleWord& DoubleWord::operator= ( Type&& rhs )
    {
        myValue = static_cast<DoubleWordType>( rhs );
        return *this;
    }
    
    std::ostream& operator<< ( std::ostream& outStream, const DoubleWord& rhs );
}
