//
//  Bitmap.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Color.hpp"
#include <list>
#include <iostream>

namespace BitmapGraphics
{
    class Bitmap
    {
    public:
    
        using ScanLine = std::list<Color>;
        
    private:
    
        using ScanLineCollection = std::list<ScanLine>;
    
    public:
    
        using ScanLineIterator = ScanLineCollection::const_iterator;
    
        Bitmap() = default;
        Bitmap ( int width, int height, std::istream& is );
        
        Bitmap ( const Bitmap& src ) = default;
        Bitmap ( Bitmap&& src ) = default;
        
        Bitmap& operator= ( const Bitmap& rhs ) = default;
        Bitmap& operator= ( Bitmap&& rhs ) = default;
        
        int getWidth() const noexcept;
        int getHeight() const noexcept;
        
        ScanLineIterator begin() const noexcept;
        ScanLineIterator end() const noexcept;
    
        void write ( std::ostream& os ) const;
    
    private:
        
        int myWidth{ 0 };
        int myHeight{ 0 };
        ScanLineCollection myScanLines;
    };
}
