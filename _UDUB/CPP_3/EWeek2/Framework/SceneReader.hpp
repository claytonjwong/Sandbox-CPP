//
//  SceneReader.hpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/5/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Element.hpp"
#include "Layer.hpp"
#include "Scene.hpp"
#include "VectorGraphic.hpp"

namespace Framework
{
    class SceneReader
    {
    public:
        
        static Scene readScene ( const Xml::Element& scene_root );

        static Layer readLayer (const Xml::HElement layer_root );
        
        static PlacedGraphic readPlacedGraphic ( const Xml::HElement placed_graphic_root );
        
        static VG::HVectorGraphic readVectorGraphic ( const Xml::HElement vector_graphic_root );
    };
}
