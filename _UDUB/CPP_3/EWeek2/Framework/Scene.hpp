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
    using LayerCollection = std::list<Layer>;
    using LayerIterator = std::list<Layer>::const_iterator;

    class Scene
    {
    public:
        
        void setHeight(const int height)
        {
            myHeight = height;
        }
        
        void setWidth(const int width)
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
        
        void push_back(const Layer& layer) noexcept
        {
            myLayers.push_back( layer );
        }
        
    private:
    
        int myHeight{ 0 };
        int myWidth{ 0 };
        LayerCollection myLayers;
        
    };
}
