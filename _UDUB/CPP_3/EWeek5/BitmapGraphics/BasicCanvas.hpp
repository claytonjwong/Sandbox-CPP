//
//  BasicCanvas.hpp
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
    struct PointComparator
    {
        bool operator ( ) ( const VG::Point& lhs, const VG::Point& rhs ) const
        {
            if ( lhs.getY() < rhs.getY() )
            {
                return true;
            }
            else
            if ( lhs.getY() > rhs.getY() )
            {
                return false;
            }
            else // Y is equal
            {
                if ( lhs.getX() <= rhs.getX() )
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    };
    
    class BasicCanvas
    {
    public:
        
        BasicCanvas ( int width, int height, const Color& background ) :
        myWidth{ width },
        myHeight{ height },
        myBackground{ background }
        {
        }
        
        const Color& getPixelColor ( const VG::Point& point ) const noexcept
        {
            auto it = myDrawing.find( point );
            
            if ( it != myDrawing.end() )
            {
                return it->second;
            }
            else
            {
                return myBackground;
            }
        }
    
        
    private:
        
        int myWidth;
        int myHeight;
        Color myBackground;
        
        std::map< VG::Point, Color, PointComparator > myDrawing;
    };
    
    
} // namespace BitmapGraphics
