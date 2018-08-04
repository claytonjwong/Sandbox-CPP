//
//  HElement.hpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/3/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "tinyxml2.h"
#include <string>
#include <unordered_map>


namespace Xml
{
    using AttributeMap=std::unordered_map<std::string,std::string>;

    class Element
    {
    public:
        
        Element(tinyxml2::XMLElement* root) : myRoot{root} {}
        
        Element(const Element& src)=delete;
        Element(const Element&& src)=delete;
        
        Element& operator=(const Element& rhs)=delete;
        Element& operator=(const Element&& rhs)=delete;
        
        std::string getName() const;
        std::string getAttribute(const std::string& name) const;
        
        AttributeMap getAttributes() const;
/*

    Xml::AttributeMap attributes = root->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(2, attributes.size());
    CHECK_EQUAL("800", attributes["width"])
    CHECK_EQUAL("600", attributes["height"])


*/
        
        
    private:
        tinyxml2::XMLElement* myRoot;
    };
    
    using HElement=Element*;
}
