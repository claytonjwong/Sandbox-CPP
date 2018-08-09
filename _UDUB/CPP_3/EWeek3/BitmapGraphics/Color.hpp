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
        
        static Color read ( std::istringstream& is ) noexcept
        {
            Component blue, green, red;
            blue.read( is );
            green.read( is );
            red.read( is );
            return Color{ red, green, blue };
        }
            
        Color ( Component red, Component green, Component blue );
        
        Component getRed() const noexcept;
        Component getGreen() const noexcept;
        Component getBlue() const noexcept;
        
    private:
    
        Component myRed;
        Component myGreen;
        Component myBlue;
        
    };
    
    std::ostream& operator<< ( std::ostream& os, const Color::Component& rhs );
}
