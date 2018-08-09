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
    Color Color::read ( std::istringstream& is ) noexcept
    {
        Component blue = Binary::Byte::read( is );
        Component green = Binary::Byte::read( is );
        Component red = Binary::Byte::read( is );
        return Color{ red, green, blue };
    }

    Color::Color ( Component red, Component green, Component blue ) :
    myRed{ red },
    myGreen{ green },
    myBlue{ blue }
    {
    }
        
    Color::Component Color::getBlue() const noexcept
    {
        return myBlue;
    }
    
    Color::Component Color::getGreen() const noexcept
    {
        return myGreen;
    }
    
    Color::Component Color::getRed() const noexcept
    {
        return myRed;
    }
    
    bool Color::operator== ( const Color& rhs )
    {
        return myRed == rhs.getRed()
            && myGreen == rhs.getGreen()
            && myBlue == rhs.getBlue();
    }
    
    std::ostream& operator<< ( std::ostream& os, const Color::Component& rhs )
    {
        os << rhs.getValue();
        return os;
    }
    
    std::ostream& operator<< ( std::ostream& os, const Color& rhs )
    {
        os << "Color{"
           << rhs.getBlue() << ", "
           << rhs.getGreen() << ", "
           << rhs.getRed()
           << "}";
        return os;
    }
}

