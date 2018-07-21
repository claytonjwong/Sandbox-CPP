//
//  Point.hpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/12/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <utility>
#include <iostream>
#include <exception>

namespace VG {
    
    class Point{
    public:
        Point()=delete;
        constexpr Point(const int x, const int y) : myX{x},myY{y} {
            if (x<0 || y<0)
                throw std::out_of_range("point values cannot be negative");
        }
        ~Point()=default;
        Point(Point& src)=default;
        Point(Point&& src)=default;
        Point& operator=(Point& rhs)=delete;
        Point& operator=(Point&& rhs)=delete;
        
        bool operator==(const Point& rhs) const noexcept;
        bool operator!=(const Point& rhs) const noexcept;
        constexpr int getX() const noexcept { return myX; }
        constexpr int getY() const noexcept { return myY; }
        
        int getHash() const noexcept {
            return (2<<20)*getX()+getY();
        }
                
    private:
        const int myX, myY;
    };
    
    std::ostream& operator<<(std::ostream& os, const Point& rhs);
    
}

#endif /* Point_hpp */
