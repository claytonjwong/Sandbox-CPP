//
//  HElement.hpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/3/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "VectorGraphic.hpp"
#include "tinyxml2.h"
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

namespace Xml
{
    class Element; // forward declaration for HElement using-declaration
    using HElement = std::shared_ptr<Element>;
    
    using HXMLElement = tinyxml2::XMLElement*;
    using HXMLNode = tinyxml2::XMLNode*;
    using ElementDocument = tinyxml2::XMLDocument;
    using AttributeMap = std::unordered_map<std::string,std::string>;
    using ElementList = std::vector<HElement>;
    using ElementError = tinyxml2::XMLError;

    class Element
    {
    public:
        
        Element(HXMLElement root = nullptr) : myRoot{ root } {}
        ~Element() = default;
        
        Element(const Element& src) = delete;
        Element(Element&& src) = delete;
        
        Element& operator=(const Element& rhs) = delete;
        Element& operator=(Element&& rhs) = delete;
        
        const static HElement make_HElement(const VG::VectorGraphic& vg);
        
        const std::string getName() const noexcept;
        const std::string getAttribute(const std::string& name) const noexcept;
        const AttributeMap getAttributes() const noexcept;
        const ElementList getChildElements() const noexcept;
        const HElement getFirstChild() const;
        
        ElementError parseXML(const std::string& xml);
        HXMLElement createXMLNode(const std::string& name);
        HXMLNode insertFirstChild( HXMLNode child );
    
    private:
        
        HXMLElement myRoot;
        ElementDocument myDocument;
        ElementList myChildren;
    };

}
