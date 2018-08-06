//
//  Scene.hpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/5/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Layer.hpp"
#include <list>

namespace Framework
{

    class Scene
    {
    public:

        using LayerCollection = std::list<Layer>;
        using LayerIterator = LayerCollection::const_iterator;

        void setHeight(const int height) noexcept
        {
            myHeight = height;
        }
        
        void setWidth(const int width) noexcept
        {
            myWidth = width;
        }
        
        int getHeight() const noexcept
        {
            return myHeight;
        }
        
        int getWidth() const noexcept
        {
            return myWidth;
        }
        
        LayerIterator begin() const noexcept
        {
            return myLayers.begin();
        }
        
        LayerIterator end() const noexcept
        {
            return myLayers.end();
        }
        
        void addLayer(const Layer& layer) noexcept
        {
            myLayers.push_back( layer );
        }
        
    private:
    
        int myHeight{ 0 };
        int myWidth{ 0 };
        LayerCollection myLayers;
        
    };
}
