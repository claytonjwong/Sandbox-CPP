//
//  Layer.cpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/5/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Layer.hpp"

namespace Framework
{
    Layer::Layer(const std::string& alias) : myAlias{ alias } {}

    const std::string& Layer::getAlias() const noexcept
    {
        return myAlias;
    }

    Layer::PlacedGraphicIterator Layer::begin() const noexcept
    {
        return myGraphics.begin();
    }

    Layer::PlacedGraphicIterator Layer::end() const noexcept
    {
        return myGraphics.end();
    }

    void Layer::addGraphic(const PlacedGraphic& graphic) noexcept
    {
        myGraphics.push_back( graphic );
    }
}
