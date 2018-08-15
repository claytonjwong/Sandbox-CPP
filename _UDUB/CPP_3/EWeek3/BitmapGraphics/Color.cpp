//
//  Color.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/7/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Byte.hpp"
#include "Color.hpp"

using namespace std;

namespace BitmapGraphics
{
    //
    // Note: significant read/write order: ( blue, green, red )
    //
    Color Color::read ( std::istream& is ) noexcept
    {
        auto blue = Binary::Byte::read( is );
        auto green = Binary::Byte::read( is );
        auto red = Binary::Byte::read( is );
        return std::move( Color{ red, green, blue } );
    }

    Color::Color ( Component red, Component green, Component blue ) :
    myRed{ red },
    myGreen{ green },
    myBlue{ blue }
    {
    }
        
    const Color::Component& Color::getBlue() const noexcept
    {
        return myBlue;
    }
    
    const Color::Component& Color::getGreen() const noexcept
    {
        return myGreen;
    }
    
    const Color::Component& Color::getRed() const noexcept
    {
        return myRed;
    }
    
    //
    // Note: significant read/write order: ( blue, green, red )
    //
    void Color::write ( std::ostream& os ) const
    {
        myBlue.write( os );
        myGreen.write( os );
        myRed.write( os );
    }
    
    bool Color::operator== ( const Color& rhs ) const noexcept
    {
        return myRed == rhs.getRed()
            && myGreen == rhs.getGreen()
            && myBlue == rhs.getBlue();
    }
    
    bool Color::operator!= ( const Color& rhs ) const noexcept
    {
        return ! ( *this == rhs );
    }
        
    std::ostream& operator<< ( std::ostream& os, const Color& rhs ) noexcept
    {
        rhs.write( os );
        return os;
    }
}

