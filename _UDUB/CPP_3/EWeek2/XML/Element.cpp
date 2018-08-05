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
        
        result->insertFirstChild( root ); // TODO: does this work to update myRoot in here?
        
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
            //
            // TODO: dive deep to also include child's children here
            // then push_back onto the result, so that Scene children are Layers and Layer children are PlacedGraphics
            //
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

    HXMLNode Element::insertFirstChild( HXMLNode child )
    {
        auto result = myDocument.InsertFirstChild( child );
        
        myRoot = myDocument.RootElement(); // TODO: double check if I want to update myRoot here or not
        
        return result;
    }
}
