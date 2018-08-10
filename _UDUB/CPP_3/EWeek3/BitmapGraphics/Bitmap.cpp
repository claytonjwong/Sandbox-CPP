//
//  Bitmap.cpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Bitmap.hpp"

namespace BitmapGraphics
{
    Bitmap::Bitmap ( int width, int height, std::istream& is ) :
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
    
    int Bitmap::getWidth() const noexcept
    {
        return myWidth;
    }

    int Bitmap::getHeight() const noexcept
    {
        return myHeight;
    }

    Bitmap::ScanLineIterator Bitmap::begin() const noexcept
    {
        return myScanLines.begin();
    }

    Bitmap::ScanLineIterator Bitmap::end() const noexcept
    {
        return myScanLines.end();
    }

    void Bitmap::write ( std::ostream& os )
    {
        TODO -- perform each scanLine writing here and ensure padding is performed!!!
    
        if ( ! os )
        {
            throw std::runtime_error{ "unable to write to ostream" };
        }
    }
}
