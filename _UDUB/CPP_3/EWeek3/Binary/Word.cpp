//
//  Word.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Word.hpp"

namespace Binary
{
    Word Word::readLittleEndian ( std::stringstream& ss )
    {
        auto first = Byte::read( ss );
        auto second = Byte::read( ss );
        return Word{
            static_cast<WordType>( first | second << 8 )
        };
    }

    Word Word::readBigEndian ( std::stringstream& ss )
    {
        auto first = Byte::read( ss );
        auto second = Byte::read( ss );
        return Word{
            static_cast<WordType>( first << 8 | second )
        };
    }

    Word::Word ( WordType value ) :
    myValue{ value }
    {
    }

    Word::operator WordType()
    {
        return myValue;
    }
}
