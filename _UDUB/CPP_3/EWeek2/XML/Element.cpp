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
        HElement result = make_shared<Element>();
        auto scene_root = result->createXMLNode( "Scene" );
        
        scene_root->SetAttribute( "height", scene.getHeight() );
        scene_root->SetAttribute( "width", scene.getWidth() );
        
        for ( const auto& layer: scene )
        {
            auto layer_root = result->createXMLNode( "Layer" );
            
            layer_root->SetAttribute( "alias", layer.getAlias().c_str() );
            
            for ( const auto& graphic: layer )
            {
                auto graphic_root = result->createXMLNode( "PlacedGraphic" );
                
                auto placement_point = graphic.getPlacementPoint();
                
                graphic_root->SetAttribute( "x", placement_point.getX() );
                graphic_root->SetAttribute( "y", placement_point.getY() );
                
                auto vg = graphic.getGraphic();
                
                auto vg_root = result->createXMLNode( "VectorGraphic" );
                vg_root->SetAttribute(  "closed", ( vg.isClosed() ? "true" : "false" )  );

// TODO: add begin() end() onto VectorGraphic
//                for ( const auto& point: graphic )
//                {
//
//                }
                
                graphic_root->InsertEndChild( vg_root );
                
                layer_root->InsertEndChild( graphic_root );
            }
            
            scene_root->InsertEndChild( layer_root );
        }
        
        result->insertChild( scene_root );
        return result;
    }
    
    const HElement Element::make_HElement(const Framework::Layer& layer)
    {
        HElement result = make_shared<Element>();
        
        return result;
    }
    
    const HElement Element::make_HElement(const Framework::PlacedGraphic& graphic)
    {
        HElement result = make_shared<Element>();
        
        return result;
    }

    const HElement Element::make_HElement(const VG::VectorGraphic& vg)
    {
        HElement result = make_shared<Element>();
        auto root = result->createXMLNode( "VectorGraphic" );
        
        root->SetAttribute(  "closed", ( vg.isClosed() ? "true" : "false" )  );
        
        for (  int i=0, N=static_cast<int>( vg.getPointCount() ); i < N; ++i  )
        {
            auto point = vg.getPoint( i );
            auto node = result->createXMLNode( "Point" );
            node->SetAttribute( "x", point.getX() );
            node->SetAttribute( "y", point.getY() );
            root->InsertEndChild( node );
        }
        
        result->insertChild( root ); // TODO: does this work to update myRoot in here?
        
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
        auto result = myRoot->Attribute(name.c_str());
        
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
    
    const HElement Element::getFirstChild() const
    {
        return make_shared<Element>( myRoot->FirstChildElement() );
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

    HXMLNode Element::insertChild(HXMLNode child)
    {
        auto result = myDocument.InsertEndChild( child );
        
        myRoot = myDocument.RootElement(); // TODO: double check if I want to update myRoot here or not
        
        return result;
    }
}
