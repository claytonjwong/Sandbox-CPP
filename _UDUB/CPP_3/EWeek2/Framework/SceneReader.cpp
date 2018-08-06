//
//  SceneReader.cpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/5/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "SceneReader.hpp"
#include "VectorGraphicStreamer.hpp"

namespace Framework
{
    Scene SceneReader::readScene(const Xml::Element& scene_root)
    {
        if ( scene_root.getName() == "Scene" )
        {
            Scene scene;
            
            auto width = scene_root.getAttribute( "width" );
            auto height = scene_root.getAttribute( "height" );
            
            scene.setWidth(  stoi( width )  );
            scene.setHeight(  stoi( height )  );
            
            for ( const auto& layer_root: scene_root.getChildElements() )
            {
                auto layer = readLayer( layer_root );
                scene.pushBack( layer );
            }
            return scene;
        }
        else
        {
            throw std::runtime_error{ "unable to find Scene in Xml::Element" };
        }
    }

    Layer SceneReader::readLayer(const Xml::HElement layer_root)
    {
        auto name = layer_root->getName();
        if ( name == "Layer" )
        {
            auto alias = layer_root->getAttribute( "alias" );
            Layer layer{ alias };
            for ( const auto& placed_graphic_root: layer_root->getChildElements() )
            {
                auto placed_graphic = readPlacedGraphic( placed_graphic_root );
                layer.addGraphic( placed_graphic );
            }
            return layer;
        }
        else
        {
            throw std::runtime_error{ "unable to find Layer int Xml::Element" };
        }
    }

    PlacedGraphic SceneReader::readPlacedGraphic(const Xml::HElement placed_graphic_root)
    {
        auto name = placed_graphic_root->getName();
        if ( name == "PlacedGraphic" )
        {
            PlacedGraphic placed_graphic;
            
            auto x = stoi (  placed_graphic_root->getAttribute( "x" )  );
            auto y = stoi (  placed_graphic_root->getAttribute( "y" )  );
            
            placed_graphic.setPlacementPoint(  VG::Point{ x,y }  );
            
            for ( const auto& vector_graphic_root: placed_graphic_root->getChildElements() )
            {
                    const auto handle_VG = readVectorGraphic( vector_graphic_root );
                    placed_graphic.setGraphic( handle_VG );
            }
            
            return placed_graphic;
        }
        else
        {
            throw std::runtime_error{ "unable to find PlacedGraphic in Xml::Element" };
        }
    }

    VG::HVectorGraphic SceneReader::readVectorGraphic(const Xml::HElement vector_graphic_root )
    {
        auto name = vector_graphic_root->getName();
        if ( name == "VectorGraphic" )
        {
            const auto handle_VG =
                std::make_shared<VG::VectorGraphic>(
                    VG::VectorGraphicStreamer::
                        getVectorGraphicFromHandle( vector_graphic_root )
                );
            return handle_VG;
        }
        else
        {
            throw std::runtime_error{ "unable to find VectorGraphic in Xml::Element" };
        }
    }
}
