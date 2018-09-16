//
//  StrokeFactory.hpp
//  EWeek5
//
//  Created by Clayton Wong on 9/13/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "IStroke.hpp"
#include "SquareStroke.hpp"

namespace BitmapGraphics
{
    
    class StrokeFactory
    {
    public:
        
        static HStroke createStroke ( const std::string& name, size_t size, Color color );
    
    };
    
} // namespace BitmapGraphics
