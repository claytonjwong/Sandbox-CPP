//
//  Color.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/7/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Byte.hpp"
#include "Color.hpp"
#

//TEST(createColor, Color)
//{
//    Color color{0xAA, 0xBB, 0xCC};
//
//    CHECK_EQUAL(0xAA, color.getRed());
//    CHECK_EQUAL(0xBB, color.getGreen());
//    CHECK_EQUAL(0xCC, color.getBlue());
//}
//
//TEST(readColor, Color)
//{
//    unsigned char colorData[]{ 0x23, 0x24, 0x25, 0 };
//    std::istringstream colorStream{reinterpret_cast<char*>(colorData)};
//
//    Color color{Color::read(colorStream)};
//
//    CHECK_EQUAL(0x23, color.getBlue());
//    CHECK_EQUAL(0x24, color.getGreen());
//    CHECK_EQUAL(0x25, color.getRed());
//}

using namespace std;

namespace BitmapGraphics
{
    

    Color::Color ( Component red, Component green, Component blue ) :
    myRed{ red },
    myGreen{ green },
    myBlue{ blue }
    {
    }
        
    Color::Component Color::getBlue() const noexcept
    {
        return myBlue;
    }
    
    Color::Component Color::getGreen() const noexcept
    {
        return myGreen;
    }
    
    Color::Component Color::getRed() const noexcept
    {
        return myRed;
    }
    
    std::ostream& operator<< ( std::ostream& os, const Color::Component& rhs )
    {
        os << rhs.getValue();
        return os;
    }

}

