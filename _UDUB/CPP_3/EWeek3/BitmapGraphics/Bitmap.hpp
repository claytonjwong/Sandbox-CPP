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
    
        Bitmap() = delete;
        Bitmap ( int width, int height, std::istream& is ) :
        myWidth{ width },
        myHeight{ height }
        {
            for ( int i = 0;  i < height;  ++i )
            {
                ScanLine scanLine;
                for ( int j = 0;  j < width;  ++j )
                {
                    auto color = Color::read( is );
                    scanLine.emplace_back(  std::move( color )  );
                }
                myScanLines.emplace_back(  std::move( scanLine )  );
            }
        }
        
        Bitmap ( const Bitmap& src ) = default;
        Bitmap ( Bitmap&& src ) = default;
        
        Bitmap& operator= ( const Bitmap& rhs ) = default;
        Bitmap& operator= ( Bitmap&& rhs ) = default;
        
        int getWidth() const noexcept
        {
            return myWidth;
        }
        
        int getHeight() const noexcept
        {
            return myHeight;
        }
        
        ScanLineIterator begin() const noexcept
        {
            return myScanLines.begin();
        }
        
        ScanLineIterator end() const noexcept
        {
            return myScanLines.end();
        }
    
    private:
        
        int myWidth{ 0 };
        int myHeight{ 0 };
        ScanLineCollection myScanLines;
    };
}
