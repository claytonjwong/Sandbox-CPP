//
//  Color.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/7/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Byte.hpp"
#include <sstream>

namespace BitmapGraphics
{
   class Color
    {
    public:
    
        using Component = Binary::Byte;
        
        static Color read ( std::istringstream& is ) noexcept;
        
        Color ( Component red, Component green, Component blue );
        
        Component getRed() const noexcept;
        Component getGreen() const noexcept;
        Component getBlue() const noexcept;
        
        bool operator== ( const Color& rhs );
        
    private:
    
        Component myRed;
        Component myGreen;
        Component myBlue;
    };
    
    std::ostream& operator<< ( std::ostream& os, const Color::Component& rhs );
    std::ostream& operator<< ( std::ostream& os, const Color& rhs );
}
