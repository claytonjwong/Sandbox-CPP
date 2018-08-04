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
        auto result = myXMLElement->Name();
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
        auto result = myXMLElement->Attribute(name.c_str());
        if ( result != nullptr )
        {
            return string{ result };
        }
        else
        {
            return {};
        }
    }
}
