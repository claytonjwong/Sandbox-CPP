//
//  IPen.hpp
//  EWeek5
//
//  Created by Clayton Wong on 9/11/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "ICanvas.hpp"
#include "Point.hpp"

namespace BitmapGraphics
{
    class IPen
    {
    public:
        
        virtual void drawPoint ( const HCanvas& canvas, const VG::Point& point ) const = 0;
    };
    
    
} // namespace BitmapGraphics
