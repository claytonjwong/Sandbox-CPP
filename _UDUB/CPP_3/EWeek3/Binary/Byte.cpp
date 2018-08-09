//
//  Byte.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/7/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Byte.hpp"
#include <iostream>

namespace Binary
{
    ByteType Byte::read ( std::istream& is ) noexcept
    {
        ByteType value;
        
        is >> value;
        
        if ( is )
        {
            return value;
        }
        else
        {
            return {};
        }
    }
    
    Byte::Byte() :
    myValue{ 0 }
    {
    }
    
    Byte::Byte ( ByteType value ) :
    myValue{ value }
    {
    }
    
    Byte::operator ByteType()
    {
        return myValue;
    }

    ByteType Byte::getValue() const noexcept
    {
        return myValue;
    }
    
    void Byte::write ( std::ostream& os )
    {
        os << myValue;
        
        if ( !(os) )
        {
            throw std::runtime_error{ "unable to write Byte to output stream" };
        }
    }
}
