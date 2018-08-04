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
#include <memory>
#include <vector>

namespace Xml
{
    class Element; // forward declaration for HElement definition
    
    using HElement = std::shared_ptr<Element>;
    using HXMLNode = tinyxml2::XMLElement*;
    using AttributeMap = std::unordered_map<std::string,std::string>;
    using ElementList = std::vector<HElement>;

    class Element
    {
    public:
        
        Element(HXMLNode root) : myRoot{root} {}
        
        Element(const Element& src) = delete;
        Element(const Element&& src) = delete;
        
        Element& operator=(const Element& rhs) = delete;
        Element& operator=(const Element&& rhs) = delete;
        
        std::string getName() const noexcept;
        std::string getAttribute(const std::string& name) const noexcept;
        
        AttributeMap getAttributes() const noexcept;
        
        ElementList getChildElements() const noexcept;
/*


*/
        
        
    private:
        HXMLNode myRoot;
    };

}
