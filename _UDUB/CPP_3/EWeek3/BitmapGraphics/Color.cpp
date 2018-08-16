//
//  Color.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/7/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Common.hpp"
#include "Byte.hpp"
#include "Color.hpp"

using namespace std;

namespace BitmapGraphics
{
    //
    // Note: significant stream read/write order: ( blue, green, red )
    //
    Color Color::read ( std::istream& is ) noexcept
    {
        auto blue = Binary::Byte::read( is );
        auto green = Binary::Byte::read( is );
        auto red = Binary::Byte::read( is );
        return std::move( Color{ red, green, blue } ); // user order: ( red, green, blue )
    }
    
    const Color::ComponentType& Color::getBlue() const noexcept
    {
        return myBlue.getValue();
    }
    
    const Color::ComponentType& Color::getGreen() const noexcept
    {
        return myGreen.getValue();
    }
    
    const Color::ComponentType& Color::getRed() const noexcept
    {
        return myRed.getValue();
    }
    
    //
    // Note: significant stream read/write order: ( blue, green, red )
    //
    void Color::write ( std::ostream& os ) const
    {
        myBlue.write( os );
        myGreen.write( os );
        myRed.write( os );
    }
    
    bool Color::operator== ( const Color& rhs ) const noexcept
    {
        return myRed.getValue() == rhs.getRed()
            && myGreen.getValue() == rhs.getGreen()
            && myBlue.getValue() == rhs.getBlue();
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

