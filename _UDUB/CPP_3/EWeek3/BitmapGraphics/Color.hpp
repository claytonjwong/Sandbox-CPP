//
//  Color.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/7/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Byte.hpp"
#include <sstream>

namespace BitmapGraphics
{
   class Color
    {
    public:
    
        using Component = Binary::Byte;
        using ComponentType = Binary::ByteType;
        
        static constexpr int BYTE_COUNT = 3;
        
        static Color read ( std::istream& inStream ) noexcept;
        
        Color() = default;
        ~Color() = default;
        
        template <typename Type>
        Color ( const Type& red, const Type& green, const Type& blue );
        
        Color ( const Color& src ) = default;
        Color ( Color&& src ) = default;
        
        Color& operator= ( const Color& rhs ) = default;
        Color& operator= ( Color&& rhs ) = default;
        
        const ComponentType& getRed() const noexcept;
        const ComponentType& getGreen() const noexcept;
        const ComponentType& getBlue() const noexcept;
        
        void write ( std::ostream& outStream ) const;
        
        bool operator== ( const Color& rhs ) const noexcept;
        bool operator!= ( const Color& rhs ) const noexcept;
        
    private:
    
        Component myRed;
        Component myGreen;
        Component myBlue;
    };
    
    template <typename Type>
    Color::Color ( const Type& red, const Type& green, const Type& blue ) :
    myRed{ static_cast<Component>( red ) },
    myGreen{ static_cast<Component>( green ) },
    myBlue{ static_cast<Component>( blue ) }
    {
    }
    
    std::ostream& operator<< ( std::ostream& outStream, const Color& rhs ) noexcept;
}
