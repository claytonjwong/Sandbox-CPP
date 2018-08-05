//
//  Layer.hpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/5/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "PlacedGraphic.hpp"
#include <list>

namespace Framework
{
    using PlacedGraphicCollection = std::list<PlacedGraphic>;
    using PlacedGraphicIterator = std::list<PlacedGraphic>::const_iterator;

    class Layer
    {
    public:
    
        Layer(const std::string& alias) : myAlias{ alias } {}
        
        PlacedGraphicIterator begin() const noexcept
        {
            return myGraphics.begin();
        }
        
        PlacedGraphicIterator end() const noexcept
        {
            return myGraphics.end();
        }
        
    private:
    
        std::string myAlias;
        PlacedGraphicCollection myGraphics;
    };
}
