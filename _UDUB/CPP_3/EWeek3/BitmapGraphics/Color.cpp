//
//  Color.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/7/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Common.hpp"
#include "Byte.hpp"
#include "Color.hpp"

using namespace std;

namespace BitmapGraphics
{
    //
    // Note: significant stream read/write order: ( blue, green, red )
    //
    Color Color::read ( std::istream& is ) noexcept
    {
        auto blue = Binary::Byte::read( is );
        auto green = Binary::Byte::read( is );
        auto red = Binary::Byte::read( is );
        return std::move( Color{ red, green, blue } ); // user order: ( red, green, blue )
    }

    Color::Color ( Component red, Component green, Component blue ) :
    myRed{ red },
    myGreen{ green },
    myBlue{ blue }
    {
    }
    
    //
    // hack
    //
    // after I made the Byte conversion constructor explicit, the following Color's constructor invocation
    // no longer matches above constructor Color::Color ( Component red, Component green, Component blue )
    //
    // Color color{0xAA, 0xBB, 0xCC};
    //
    // so here's what I came up with below.  If the above constructor should be invoked instead,
    // how should I change my code?  Obviously this is ugly and redundant, but I'm not sure how to fix it
    // unless I remove explicit from the Byte conversion constructor:
    //
    // explicit Byte ( ByteType value );
    //
    Color::Color ( std::initializer_list<Binary::ByteType> initList )
    {
        if ( initList.size() != 3 )
        {
            throw runtime_error{ "color must be initialized with 3 components: red, green, blue" };
        }
        
        auto it = initList.begin();
        
        myRed = Binary::Byte{ *it++ };
        myGreen = Binary::Byte{ *it++ };
        myBlue = Binary::Byte{ *it++ };
        
        Binary::verifyEquality( it, initList.end(),
            "color must be initialized with 3 components: red, green, blue" );
    }
    
    const Color::Component& Color::getBlue() const noexcept
    {
        return myBlue;
    }
    
    const Color::Component& Color::getGreen() const noexcept
    {
        return myGreen;
    }
    
    const Color::Component& Color::getRed() const noexcept
    {
        return myRed;
    }
    
    //
    // Note: significant stream read/write order: ( blue, green, red )
    //
    void Color::write ( std::ostream& os ) const
    {
        myBlue.write( os );
        myGreen.write( os );
        myRed.write( os );
    }
    
    bool Color::operator== ( const Color& rhs ) const noexcept
    {
        return myRed == rhs.getRed()
            && myGreen == rhs.getGreen()
            && myBlue == rhs.getBlue();
    }
    
    bool Color::operator!= ( const Color& rhs ) const noexcept
    {
        return ! ( *this == rhs );
    }
        
    std::ostream& operator<< ( std::ostream& os, const Color& rhs ) noexcept
    {
        rhs.write( os );
        return os;
    }
}

