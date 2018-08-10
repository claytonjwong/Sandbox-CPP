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
    Byte Byte::read ( std::istream& is ) noexcept
    {
        Byte value;
        
        is >> value.myValue;
        
        if ( is )
        {
            return value;
        }
        else
        {
            return {};
        }
    }
        
    Byte::Byte ( ByteType value ) :
    myValue{ value }
    {
    }
    
    ByteType Byte::getValue() const noexcept
    {
        return myValue;
    }
    
    void Byte::write ( std::ostream& os ) const
    {
        os << myValue;
        
        if ( !(os) )
        {
            throw std::runtime_error{ "unable to write Byte to output stream" };
        }
    }
    
    Byte::operator ByteType()
    {
        return myValue;
    }
    
    bool Byte::operator== ( const Byte& rhs ) const noexcept
    {
        return myValue == rhs.myValue;
    }
}
