//
//  Stroke_t.hpp
//  EWeek5
//
//  Created by Clayton Wong on 9/16/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

namespace BitmapGraphics
{
    template< typename PenType >
    class Stroke_t : public IStroke
    {
    public:
        
        Stroke_t ( const std::string& name, const size_t size, const Color& color );
        
        virtual const std::string& getName ( ) const noexcept override;
        
        virtual size_t getSize ( ) const noexcept override;
        
        virtual Color getColor ( ) const noexcept override;
        
        virtual HPen createPen ( ) const noexcept override;
        
    private:
        
        std::string myName;
        size_t mySize;
        Color myColor;
    };
    
    
    template< typename PenType >
    Stroke_t< PenType >::Stroke_t ( const std::string& name, const size_t size, const Color& color ) :
    myName{ name },
    mySize{ size },
    myColor{ color }
    {
    }
    
    
    template< typename PenType >
    const std::string& Stroke_t< PenType >::getName ( ) const noexcept
    {
        return myName;
    }
    
    
    template< typename PenType >
    size_t Stroke_t< PenType >::getSize ( ) const noexcept
    {
        return mySize;
    }
    
    
    template< typename PenType >
    Color Stroke_t< PenType >::getColor ( ) const noexcept
    {
        return myColor;
    }
    
    
    template< typename PenType >
    HPen Stroke_t< PenType >::createPen ( ) const noexcept
    {
        return std::make_shared< PenType >( myName, mySize, myColor );
    }

    
} // namespace BitmapGraphics
