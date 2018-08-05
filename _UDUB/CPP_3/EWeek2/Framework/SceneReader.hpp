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
#include "VectorGraphicStreamer.hpp"
#include <memory>

/*

<Scene width="800" height="600">
  <Layer alias="sky">
    <PlacedGraphic x="0" y="0">
      <VectorGraphic closed="true">
        <Point x="1" y="2" />
        <Point x="3" y="4" />
        <Point x="5" y="6" />
      </VectorGraphic>
    </PlacedGraphic>
    <PlacedGraphic x="700" y="0">
      <VectorGraphic closed="true">
        <Point x="7" y="8" />
        <Point x="9" y="10" />
        <Point x="11" y="12" />
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
  <Layer alias="mountains">
    <PlacedGraphic x="250" y="250">
      <VectorGraphic closed="false">
        <Point x="13" y="14" />
        <Point x="15" y="19" />
        <Point x="17" y="18" />
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
</Scene>);
*/

namespace Framework
{
    class SceneReader
    {
    public:
        
        static Scene readScene(const Xml::Element& root)
        {
            Scene s;
            if ( root.getName() == "Scene" )
            {
                auto height = root.getAttribute( "height" );
                s.setHeight(  stoi( height )  );
            
                auto width = root.getAttribute( "width" );
                s.setWidth(  stoi( width )  );
                
                for ( const auto& scene_child: root.getChildElements() )
                {
                    auto scene_child_name = scene_child->getName();
                    if ( scene_child_name == "Layer" )
                    {
                        auto alias = scene_child->getAttribute( "alias" );
                        Layer layer{ alias };
                        
                        for ( const auto& layer_child: scene_child->getChildElements() )
                        {
                            auto layer_child_name = layer_child->getName();
                            if ( layer_child_name == "PlacedGraphic" )
                            {
                                PlacedGraphic graphic;
                                
                                auto x = stoi (  layer_child->getAttribute( "x" )  );
                                auto y = stoi (  layer_child->getAttribute( "y" )  );
                                
                                graphic.setPlacementPoint( VG::Point{ x,y } );
                                
                                auto placed_graphic_child = layer_child->getFirstChild();
                                if ( placed_graphic_child->getName() == "VectorGraphic" )
                                {                                    
                                    const auto handle_VG =
                                        std::make_shared<VG::VectorGraphic>(
                                            VG::VectorGraphicStreamer::
                                                getVectorGraphicFromHandle( placed_graphic_child )
                                        );
                                        
                                    graphic.setGraphic( handle_VG );
                                }
                                
                                layer.addGraphic( graphic );
                            }
                        }
                        
                        s.addLayer( layer );
                    }
                }

            }
            return s;
        }
        
    };
}

/*

    auto s = Framework::SceneReader::readScene(*root);

    CHECK_EQUAL(800, s.getWidth());
    CHECK_EQUAL(600, s.getHeight());


*/
