//
//  Word.hpp
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
    using WordType = uint16_t;
    
    class Word
    {
    public:
    
        static constexpr int BYTE_COUNT = 2;
    
        static Word read ( std::istream& inStream, const Endianness&& forceEndian=Endianness::Dynamic );
        static Word readLittleEndian ( std::istream& inStream );
        static Word readBigEndian ( std::istream& inStream );

    private:
    
        static void read ( std::istream& inStream, Byte& first, Byte& second );
        
    public:

        Word() = default;
        ~Word() = default;
        explicit Word ( WordType value );
        Word ( const Byte& first, const Byte& second );
        
        Word ( const Word& src ) = default;
        Word ( Word&& src ) = default;
        
        Word& operator= ( const Word& rhs ) = default;
        Word& operator= ( Word&& rhs ) = default;
        
        Word& operator= ( const WordType& rhs );
        Word& operator= ( WordType&& rhs );
        
        const WordType& getValue() const noexcept;

        void write ( std::ostream& outStream, const Endianness&& forceEndian=Endianness::Dynamic ) const;
        void writeLittleEndian ( std::ostream& outStream ) const;
        void writeBigEndian ( std::ostream& outStream ) const;
        
    private:
    
        static void write ( std::ostream& outStream, const Byte& first, const Byte& second );

    public:
        
        operator WordType() const noexcept;
        
        bool operator== ( const Word& rhs ) const noexcept;
        
    private:
    
        WordType myValue{ 0 };
    };
    
    std::ostream& operator<< ( std::ostream& outStream, const Word& rhs );
}
