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

//TEST(pushBack, Scene)
//{
//    Framework::Scene scene(800, 600);
//    scene.pushBack(Framework::Layer("Mountains"));
//    scene.pushBack(Framework::Layer("Sea"));
//    scene.pushBack(Framework::Layer("Sky"));
//
//    LayerMatcher matcher = std::for_each(scene.begin(), scene.end(), LayerMatcher());
//    CHECK(matcher.allLayersFound());
//}


namespace Framework
{

    class Scene
    {
    public:

        using LayerCollection = std::list<Layer>;
        using LayerIterator = LayerCollection::const_iterator;

        Scene() = default;
        Scene(int width, int height) : myWidth{ width }, myHeight{ height } {}

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
        
        void pushBack(const Layer& layer) noexcept
        {
            myLayers.push_back( layer );
        }
        
        void remove(const Layer& target) noexcept
        {
            auto new_end = std::remove_if( myLayers.begin(), myLayers.end(),
                [&](const Layer& x){ return x.getAlias() == target.getAlias(); });
            
            if ( new_end != myLayers.end() )
            {
                myLayers.erase( new_end, myLayers.end() );
            }
        }
        
    private:
    
        int myHeight{ 0 };
        int myWidth{ 0 };
        LayerCollection myLayers;
        
    };
}
