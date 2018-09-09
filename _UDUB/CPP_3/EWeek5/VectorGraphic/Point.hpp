//
//  Point.hpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/12/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include <iostream>
#include <exception>

namespace VG
{
    class Point
    {
    public:
      
        constexpr Point ( int x=0, int y=0 ) :
        myX{ x },
        myY{ y }
        {
            if ( x < 0 || y < 0 )
            {
                throw std::out_of_range("point values cannot be negative");
            }
        }
        
        ~Point()=default;
        
        Point ( const Point& src ) = default;
        Point ( Point&& src ) = default;
        
        Point& operator= ( const Point& rhs ) = default;
        Point& operator= ( Point&& rhs ) = default;
        
        constexpr int getX ( ) const noexcept { return myX; }
        constexpr int getY ( ) const noexcept { return myY; }
        
        bool isInBounds ( const Point& minPoint, const Point& maxPoint ) const noexcept;
        
        bool operator< ( const Point& rhs ) const noexcept;
        
    private:
        int myX{ 0 };
        int myY{ 0 };
    };
    
    bool operator== ( const Point& lhs, const Point& rhs );
    bool operator!= ( const Point& lhs, const Point& rhs );
    
    std::ostream& operator<< ( std::ostream& os, const Point& rhs );
    
    /*
    struct PointComparator
    {
        bool operator ( ) ( const VG::Point& lhs, const VG::Point& rhs ) const
        {
            if ( lhs == rhs )
            {
                return true;
            }
            
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
     */
}


