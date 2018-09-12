//
//  SquarePen.cpp
//  EWeek5
//
//  Created by Clayton Wong on 9/11/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "SquarePen.hpp"

namespace BitmapGraphics
{
    
    
    SquarePen::SquarePen ( size_t size, Color color ) :
    mySize{ size },
    myColor{ color }
    {
    }
    
    
    void SquarePen::drawPoint ( const HCanvas& canvas, const VG::Point& topLeft ) const
    {
        for ( auto x{ topLeft.getX() };  x < mySize;  ++x )
        {
            for ( auto y{ topLeft.getY() };  y < mySize;  ++y )
            {
                canvas->setPixelColor(  VG::Point{ x, y }, myColor  );
            }
        }
    }
    
    
} // namespace BitmapGraphics
