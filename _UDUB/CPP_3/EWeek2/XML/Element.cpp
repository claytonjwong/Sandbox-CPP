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
    const string Element::getName() const noexcept
    {
        updateOriginalRoot();
        
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
        updateOriginalRoot();

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
        updateOriginalRoot();

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
        updateOriginalRoot();

        ElementList result;
        for ( auto child = myRoot->FirstChildElement();
              child != nullptr;
              child = child->NextSiblingElement() )
        {
            result.push_back(  make_shared<Element>( child )  );
        }
        
        return result;
    }
}
