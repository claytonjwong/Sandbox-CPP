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
        
        static constexpr int BYTE_COUNT = 3;
        
        static Color read ( std::istream& is ) noexcept;
        
        Color() = default;
        ~Color() = default;
        Color ( Component red, Component green, Component blue );
        
        Color ( const Color & src ) = default;
        Color ( Color&& src ) = default;
        
        Color& operator= ( const Color& rhs ) = default;
        Color& operator= ( Color&& rhs ) = default;
        
        Component getRed() const noexcept;
        Component getGreen() const noexcept;
        Component getBlue() const noexcept;
        
        void write ( std::ostream& os ) const;
        
        bool operator== ( const Color& rhs ) const noexcept;
        bool operator!= ( const Color& rhs ) const noexcept;
        
    private:
    
        Component myRed;
        Component myGreen;
        Component myBlue;
    };
    
    std::ostream& operator<< ( std::ostream& os, const Color& rhs ) noexcept;
}
