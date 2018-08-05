//
//  SceneReader.hpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/5/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Element.hpp"
#include "Scene.hpp"

namespace Framework
{
    class SceneReader
    {
    public:
        
        static Scene readScene(const Xml::Element& element)
        {
            Scene s;
            return s;
        }
        
    };
}

/*

    auto s = Framework::SceneReader::readScene(*root);

    CHECK_EQUAL(800, s.getWidth());
    CHECK_EQUAL(600, s.getHeight());


*/
