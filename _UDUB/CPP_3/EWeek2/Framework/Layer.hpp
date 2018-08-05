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

    class Layer
    {
    public:

        using PlacedGraphicCollection = std::list<PlacedGraphic>;
        using PlacedGraphicIterator = std::list<PlacedGraphic>::const_iterator;

        Layer(const std::string& alias) : myAlias{ alias } {}
        
        const std::string& getAlias() const noexcept
        {
            return myAlias;
        }
        
        PlacedGraphicIterator begin() const noexcept
        {
            return myGraphics.begin();
        }
        
        PlacedGraphicIterator end() const noexcept
        {
            return myGraphics.end();
        }
        
        void addGraphic(const PlacedGraphic& graphic) noexcept
        {
            myGraphics.push_back( graphic );
        }
        
    private:
    
        std::string myAlias;
        PlacedGraphicCollection myGraphics;
    };
}
