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
    class Element; // forward declaration for HElement using-declaration
    
    using HElement = std::shared_ptr<const Element>;
    using HXMLNode = const tinyxml2::XMLElement* const;
    using AttributeMap = std::unordered_map<std::string,std::string>;
    using ElementList = std::vector<const HElement>;

    class Element
    {
    public:
        
        Element(HXMLNode root) : myRoot{root} {}
        ~Element() = default;
        
        Element(const Element& src) = delete;
        Element(const Element&& src) = delete;
        
        Element& operator=(const Element& rhs) = delete;
        Element& operator=(const Element&& rhs) = delete;
        
        const std::string getName() const noexcept;
        const std::string getAttribute(const std::string& name) const noexcept;
        const AttributeMap getAttributes() const noexcept;
        const ElementList getChildElements() const noexcept;
        
    private:
    
        const HXMLNode myRoot;
    };

}
