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
                
                for ( const auto& child: root.getChildElements() )
                {
                    auto name = child->getName();
                    if ( name == "Layer" )
                    {
                        auto alias = child->getAttribute( "alias" );
                        Layer layer{ alias };
                        s.push_back( layer );
//                        auto x = stoi(  child->getAttribute( "x" )  );
//                        auto y = stoi(  child->getAttribute( "y" )  );
//                        vg.addPoint(  Point{ x, y }  );
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
