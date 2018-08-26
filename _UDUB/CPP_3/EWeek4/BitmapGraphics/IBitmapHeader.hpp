//
//  IBitmapHeader.hpp
//  EWeek4
//
//  Created by CLAYTON WONG on 8/26/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include <iostream>

namespace BitmapGraphics
{

    class IBitmapHeader;
    using HBitmapHeader = std::shared_ptr<IBitmapHeader>;

    class IBitmapHeader
    {
    public:
        
        virtual void read ( std::istream& inStream ) = 0;
        
        virtual void write ( std::ostream& outStream ) = 0;
    };
}
