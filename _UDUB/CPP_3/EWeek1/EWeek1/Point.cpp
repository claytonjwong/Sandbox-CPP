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
    
    bool Point::operator==(const Point& rhs) const noexcept {
        return myX==rhs.myX && myY==rhs.myY;
    }
    
    bool Point::operator!=(const Point& rhs) const noexcept {
        return !(*this==rhs);
    }

    ostream& operator<<(ostream& os, const Point& rhs) {
        os << "(" << rhs.getX() << "," << rhs.getY() << ")";
        return os;
    }
}
