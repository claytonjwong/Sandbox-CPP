//
//  Scene.hpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/5/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

namespace Framework
{
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
        
    private:
    
        int myHeight{ 0 };
        int myWidth{ 0 };
    };
}
