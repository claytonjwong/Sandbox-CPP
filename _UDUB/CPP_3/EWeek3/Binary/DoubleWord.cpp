//
//  DoubleWord.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "DoubleWord.hpp"

namespace Binary
{
    DoubleWord DoubleWord::readLittleEndian ( std::istream& ss )
    {
        auto first  = Byte::read( ss );
        auto second = Byte::read( ss );
        auto third  = Byte::read( ss );
        auto fourth = Byte::read( ss );
        
        auto size = Byte::BITS * sizeof( ByteType );
        return DoubleWord{
            static_cast<DoubleWord>(
                first  << ( 0 * size) |
                second << ( 1 * size) |
                third  << ( 2 * size) |
                fourth << ( 3 * size)
            )
        };
//        return DoubleWord{
//            static_cast<DoubleWord>( first | second << 8 | third << 16 | fourth << 24 )
//        };
    }

    DoubleWord DoubleWord::readBigEndian ( std::istream& ss )
    {
        auto first  = Byte::read( ss );
        auto second = Byte::read( ss );
        auto third  = Byte::read( ss );
        auto fourth = Byte::read( ss );
        
        auto size = Byte::BITS * sizeof( ByteType );
        return DoubleWord{
            static_cast<DoubleWord>(
                first  << ( 3 * size) |
                second << ( 2 * size) |
                third  << ( 1 * size) |
                fourth << ( 0 * size)
            )
        };
//        return DoubleWord{
//            static_cast<DoubleWord>( first << 24 | second << 16 | third << 8 | fourth )
//        };
    }

    DoubleWord::DoubleWord( DoubleWordType value ) :
    myValue{ value }
    {
    }

    DoubleWord::operator DoubleWordType()
    {
        return myValue;
    }
    
    bool DoubleWord::operator== ( const DoubleWord& rhs ) const noexcept
    {
        return myValue == rhs.myValue;
    }
}
