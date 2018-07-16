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

namespace VG {
    class Point{
    public:
        Point(const int x, const int y) : myX{x},myY{y} {}
        bool operator==(const Point& rhs) const;
        bool operator!=(const Point& rhs) const;
        constexpr int getX() const;
        constexpr int getY() const;
    private:
        const int myX, myY;
    };
    std::ostream& operator<<(std::ostream& os, const Point& rhs);
}

#endif /* Point_hpp */
