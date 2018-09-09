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
    class BasicCanvas
    {
    public:
        
        BasicCanvas ( int width, int height, const Color& background ) :
        myWidth{ width },
        myHeight{ height },
        myMin{ VG::Point{0,0} },
        myMax{ VG::Point{myWidth,myHeight} },
        myBackground{ background }
        {
        }
        
        int getWidth ( ) const noexcept
        {
            return myWidth;
        }
        
        int getHeight ( ) const noexcept
        {
            return myHeight;
        }
        
        const Color& getPixelColor ( const VG::Point& point ) const
        {
            if (  ! point.isInBounds( myMin, myMax )  )
            {
                throw std::out_of_range{ "cannot get pixel color since the point is out-of-bounds" };
            }
            
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
        
        void setPixelColor ( const VG::Point& point, const Color& color )
        {
            if (  ! point.isInBounds( myMin, myMax )  )
            {
                throw std::out_of_range{ "cannot set pixel color since the point is out-of-bounds" };
            }

            myDrawing.insert( pointColor( point, color ) );
        }
    
        
    private:
        
        const int myWidth, myHeight;
        const VG::Point myMin, myMax;
        Color myBackground;
        
        using pointColor = std::pair< VG::Point, Color >;
        std::map< VG::Point, Color > myDrawing;
    };
    
    
} // namespace BitmapGraphics
