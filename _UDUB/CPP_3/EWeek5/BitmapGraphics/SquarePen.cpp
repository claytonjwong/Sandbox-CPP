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
    
    
    void SquarePen::drawPoint ( const HCanvas& canvas, const VG::Point& topLeftPoint ) const
    {
        for ( auto x{ topLeftPoint.getX() };  x < mySize;  ++x )
        {
            for ( auto y{ topLeftPoint.getY() };  y < mySize;  ++y )
            {
                VG::Point currPoint{ x, y };
                canvas->setPixelColor( currPoint, myColor );
            }
        }
    }
    
    
} // namespace BitmapGraphics
