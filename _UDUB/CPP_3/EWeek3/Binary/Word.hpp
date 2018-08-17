//
//  Word.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "MultiByte_t.hpp"

namespace Binary
{
    using Word = MultiByte_t<uint16_t>;
    using WordType = uint16_t;
}


/*

#include "Common.hpp"
#include "Byte.hpp"
#include <sstream>
#include <list>

namespace Binary
{
    using WordType = uint16_t;
    
    class Word
    {
    public:
    
        static constexpr int BYTE_COUNT{  sizeof( WordType )  };
    
        static Word read ( std::istream& inStream, const Endianness&& forceEndian=Endianness::Dynamic );
        static Word readLittleEndian ( std::istream& inStream );
        static Word readBigEndian ( std::istream& inStream );

    private:
    
        static void read ( std::istream& inStream, std::list<Byte>& bytes );
        
    public:

        Word() = default;
        ~Word() = default;
        explicit Word ( WordType value );
        explicit Word ( const std::list<Byte>& bytes );
        
        Word ( const Word& src ) = default;
        Word ( Word&& src ) = default;
        
        Word& operator= ( const Word& rhs ) = default;
        Word& operator= ( Word&& rhs ) = default;
        
        template <typename Type>
        Word& operator= ( Type&& rhs );
        
        const WordType& getValue() const noexcept;

        void write ( std::ostream& outStream, const Endianness&& forceEndian=Endianness::Dynamic ) const;
        void writeLittleEndian ( std::ostream& outStream ) const;
        void writeBigEndian ( std::ostream& outStream ) const;
        
    private:
    
        static void write( std::ostream& outStream, const std::list<Byte>& bytes );

    public:
        
        operator WordType() const noexcept;
        
        bool operator== ( const Word& rhs ) const noexcept;
        
    private:
    
        WordType myValue{ 0 };
    };
    
    template <typename Type>
    Word& Word::operator= ( Type&& rhs )
    {
        myValue = static_cast<WordType>( rhs );
        return *this;
    }
    
    std::ostream& operator<< ( std::ostream& outStream, const Word& rhs );
}
*/

