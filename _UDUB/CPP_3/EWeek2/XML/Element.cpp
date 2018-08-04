//
//  HElement.cpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/3/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Element.hpp"

using namespace std;

namespace Xml
{
    string Element::getName() const
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
    
    string Element::getAttribute(const string& name) const
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
    
    AttributeMap Element::getAttributes() const
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
}
