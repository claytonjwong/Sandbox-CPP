//
//  SceneWriter.hpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/5/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Element.hpp"
#include "Scene.hpp"

//    Xml::HElement root = Framework::SceneWriter::writeScene(scene); // TODO make_HElement from scene

namespace Framework
{
    class SceneWriter
    {
    public:
        
        static Xml::HElement writeScene(const Scene& scene)
        {
            Xml::HElement result = Xml::Element::make_HElement( scene );
            return result;
        }
    };
}
