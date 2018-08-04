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
    string Element::getName() const noexcept
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
    
    string Element::getAttribute(const string& name) const noexcept
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
    
    AttributeMap Element::getAttributes() const noexcept
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
    
    ElementList Element::getChildElements() const noexcept
    {
        ElementList result;
        
        for ( auto child = myRoot->FirstChildElement();
              child != nullptr;
              child = child->NextSiblingElement() )
        {
            result.push_back( make_shared<Element>( child ) );
        }
        
        return result;
    }
}
