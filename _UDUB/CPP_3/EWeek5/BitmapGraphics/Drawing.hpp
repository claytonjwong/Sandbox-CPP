//
//  Drawing.hpp
//  EWeek5
//
//  Created by Clayton Wong on 9/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Color.hpp"
#include "Point.hpp"
#include <map>

namespace BitmapGraphics
{
    
    
    class Drawing
    {
    public:
        
        Drawing ( const Color& background );
        ~Drawing ( ) = default;
        
        Drawing ( const Drawing& src ) = default;
        Drawing ( Drawing&& src ) = default;
        
        Drawing& operator= ( const Drawing& rhs ) = default;
        Drawing& operator= ( Drawing&& rhs ) = default;
        
        Color getPixelColor ( const VG::Point& point ) const noexcept;
        
        void setPixelColor ( const VG::Point& point, const Color& color ) noexcept;
        
    private:
        std::map< VG::Point, Color > myDrawing;
        Color myBackground;
    };
    
    
} // namespace BitmapGraphics
