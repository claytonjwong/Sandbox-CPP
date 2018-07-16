//
//  Point.cpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/12/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Point.hpp"
#include <iostream>

using namespace std;

namespace VG {
    
    bool Point::operator==(const Point& rhs) const {
        return myX==rhs.myX && myY==rhs.myY;
    }
    
    bool Point::operator!=(const Point& rhs) const {
        return !(*this==rhs);
    }
    
    constexpr int Point::getX() const {
        return myX;
    }
    
    constexpr int Point::getY() const {
        return myY;
    }
    
    ostream& operator<<(ostream& os, const Point& rhs) {
        os << "(" << rhs.getX() << "," << rhs.getY() << ")";
        return os;
    }
}
