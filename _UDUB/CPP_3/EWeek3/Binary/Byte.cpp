//
//  Byte.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/7/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Byte.hpp"

namespace Binary
{
    Byte Byte::read ( std::istream& is ) noexcept
    {
        Byte byte;
        
        char buffer;
        is.get( buffer );
        byte.myValue = static_cast<ByteType>( buffer );
        
        if ( is )
        {
            return std::move( byte );
        }
        else
        {
            throw std::runtime_error{ "unable to read Byte from istream" };
        }
    }
        
    Byte::Byte ( ByteType value ) :
    myValue{ value }
    {
    }
    
    const ByteType& Byte::getValue() const noexcept
    {
        return myValue;
    }
    
    void Byte::write ( std::ostream& os ) const
    {
        os.put( myValue );
        
        if ( !(os) )
        {
            throw std::runtime_error{ "unable to write Byte to ostream" };
        }
    }
    
    Byte::operator ByteType() const noexcept
    {
        return myValue;
    }
    
    bool Byte::operator== ( const Byte& rhs ) const noexcept
    {
        return myValue == rhs.myValue;
    }
    
    std::ostream& operator<< ( std::ostream& os, const Byte& rhs )
    {
        rhs.write( os );
        return os;
    }
}
