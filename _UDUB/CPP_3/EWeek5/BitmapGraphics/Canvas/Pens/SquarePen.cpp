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
    
    
    SquarePen::SquarePen ( const std::string& name, size_t size, Color color ) :
    myName{ name },
    mySize{ size},
    myColor{ color }
    {
    }
    
    
    const std::string& SquarePen::getName ( ) const noexcept
    {
        return myName;
    }
    
    
    size_t SquarePen::getSize ( ) const noexcept
    {
        return mySize;
    }
    
    
    Color SquarePen::getColor ( ) const noexcept
    {
        return myColor;
    }
    
    
    void SquarePen::drawPoint ( const HCanvas& canvas, const VG::Point& topLeft ) const noexcept
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
