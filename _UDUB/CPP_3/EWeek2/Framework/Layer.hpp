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
        using PlacedGraphicIterator = PlacedGraphicCollection::const_iterator;

        Layer(const std::string& alias);
        
        const std::string& getAlias() const noexcept;
        
        PlacedGraphicIterator begin() const noexcept;
        PlacedGraphicIterator end() const noexcept;
        
        void addGraphic(const PlacedGraphic& graphic) noexcept;
        
    private:
    
        std::string myAlias;
        PlacedGraphicCollection myGraphics;
    };
}
