//
//  HElement.cpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/3/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Element.hpp"
#include <iostream>

using namespace std;

namespace Xml
{
    const HElement Element::make_HElement(const Framework::Scene& scene)
    {
        HElement handle = make_shared<Element>();
        auto scene_root = handle->createXMLNode( "Scene" );
        
        scene_root->SetAttribute( "height", scene.getHeight() );
        scene_root->SetAttribute( "width", scene.getWidth() );
        
        for ( const auto& layer: scene )
        {
            auto layer_root = make_HXMLNode( handle, layer );
            scene_root->InsertEndChild( layer_root );
        }
        
        handle->insertXMLNode( scene_root );
        return handle;
    }
    
    HXMLNode Element::make_HXMLNode(HElement handle, const Framework::Layer& layer)
    {
        auto layer_root = handle->createXMLNode( "Layer" );
        
        layer_root->SetAttribute( "alias", layer.getAlias().c_str() );
        
        for ( const auto& graphic: layer )
        {
            auto graphic_root = make_HXMLNode( handle, graphic );
            layer_root->InsertEndChild( graphic_root );
        }
        
        return layer_root;
    }
    
    HXMLNode Element::make_HXMLNode(HElement handle, const Framework::PlacedGraphic& graphic)
    {
        auto graphic_root = handle->createXMLNode( "PlacedGraphic" );
        
        auto placement_point = graphic.getPlacementPoint();

        graphic_root->SetAttribute( "x", placement_point.getX() );
        graphic_root->SetAttribute( "y", placement_point.getY() );

        auto vg = graphic.getGraphic();

        auto vg_root = make_HXMLNode( handle, vg );

        graphic_root->InsertEndChild( vg_root );

        return graphic_root;
    }
    
    HXMLNode Element::make_HXMLNode(HElement handle, const VG::VectorGraphic& vg)
    {
        auto vg_root = handle->createXMLNode( "VectorGraphic" );
        
        vg_root->SetAttribute(  "closed", ( vg.isClosed() ? "true" : "false" )  );
        
        for ( const auto& point: vg )
        {
            auto point_root = make_HXMLNode( handle, point );
            vg_root->InsertEndChild( point_root );
        }
        
        return vg_root;
    }
    
    HXMLNode Element::make_HXMLNode(HElement handle, const VG::Point& point)
    {
        auto point_root = handle->createXMLNode( "Point" );
        
        point_root->SetAttribute( "x", point.getX() );
        point_root->SetAttribute( "y", point.getY() );
        
        return point_root;
    }

    const HElement Element::make_HElement(const VG::VectorGraphic& vg)
    {
        HElement result = make_shared<Element>();
        auto root = result->createXMLNode( "VectorGraphic" );
        
        root->SetAttribute(  "closed", ( vg.isClosed() ? "true" : "false" )  );
        
        for (  int i=0, N=static_cast<int>( vg.getPointCount() );  i < N;  ++i  )
        {
            auto point = vg.getPoint( i );
            auto node = result->createXMLNode( "Point" );
            node->SetAttribute( "x", point.getX() );
            node->SetAttribute( "y", point.getY() );
            root->InsertEndChild( node );
        }
        
        result->insertXMLNode( root ); // TODO: does this work to update myRoot in here?
        
        return result;
    }

    const string Element::getName() const noexcept
    {
        auto result = myRoot->Name();
        
        if ( result != nullptr )
        {
            return string{ result };
        }
        else
        {
            return {};
        }
    }
    
    const string Element::getAttribute(const string& name) const noexcept
    {
        auto result = myRoot->Attribute( name.c_str() );
        
        if ( result != nullptr )
        {
            return string{ result };
        }
        else
        {
            return {};
        }
    }
    
    const AttributeMap Element::getAttributes() const noexcept
    {
        AttributeMap result;
        
        for ( auto attribute = myRoot->FirstAttribute();
              attribute != nullptr;
              attribute = attribute->Next() )
        {
            result[ attribute->Name() ] = attribute->Value();
        }
        return result;
    }
    
    const ElementList Element::getChildElements() const noexcept
    {
        ElementList result;
        for ( auto child = myRoot->FirstChildElement();
              child != nullptr;
              child = child->NextSiblingElement() )
        {
            result.push_back(  make_shared<Element>( child )  );
        }
        
        return result;
    }
        
    ElementError Element::parseXML(const std::string& xml)
    {
        auto result = myDocument.Parse( xml.c_str() );
        
        myRoot = myDocument.RootElement(); // TODO: double check if I want to update myRoot here or not
        
        return result;
    }

    HXMLElement Element::createXMLNode(const std::string& name)
    {
        return myDocument.NewElement( name.c_str() );
    }

    HXMLNode Element::insertXMLNode(HXMLNode node)
    {
        auto result = myDocument.InsertEndChild( node );
        
        myRoot = myDocument.RootElement(); // TODO: double check if I want to update myRoot here or not
        
        return result;
    }
}
