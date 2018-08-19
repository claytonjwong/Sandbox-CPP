//
//  Byte.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/7/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Byte.hpp"

using namespace std;

namespace Binary
{

    Byte Byte::read ( istream& inStream )
    {
        Byte byte;
        
        char buffer;
        inStream.get( buffer );
        byte.myValue = static_cast<ByteType>( buffer );
        
        if ( inStream )
        {
            return std::move( byte );
        }
        else
        {
            throw runtime_error{ "unable to read Byte from istream" };
        }
    }
    
    
    Byte::Byte ( const ByteType& value ) :
    myValue{ value }
    {
    }
    
    
    const ByteType& Byte::getValue() const noexcept
    {
        return myValue;
    }
    
    
    void Byte::write ( ostream& outStream ) const
    {
        outStream.put( myValue );
        
        if ( ! outStream )
        {
            throw runtime_error{ "unable to write Byte to ostream" };
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
    
    
    ostream& operator<< ( ostream& outStream, const Byte& rhs )
    {
        rhs.write( outStream );
        
        return outStream;
    }
    
    
}

