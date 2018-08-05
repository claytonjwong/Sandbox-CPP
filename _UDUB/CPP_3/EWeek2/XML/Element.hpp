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
        
        const std::string getName() const noexcept;
        const std::string getAttribute(const std::string& name) const noexcept;
        const AttributeMap getAttributes() const noexcept;
        const ElementList getChildElements() const noexcept;
        
        ElementError parseXML(const std::string& xml)
        {
            return myDocument.Parse( xml.c_str() );
        }
        
        HXMLElement createXMLNode(const std::string& name)
        {
            return myDocument.NewElement( name.c_str() );
        }
        
        HXMLNode insertFirstChild( HXMLNode child )
        {
            return myDocument.InsertFirstChild( child );
        }
    
    private:
        
        void updateOriginalRoot() const
        {
            //
            // is myRoot is null, then update myRoot to point towards
            // the beginning of the original copy of the document
            //
            // otherwise no-op if myRoot is NOT null, because this element
            // was constructed by pointing myRoot towards some node in the original document
            //
            if ( myRoot == nullptr )
            {
                myRoot = const_cast<HXMLElement>( myDocument.RootElement() );
            }
        }
        
        mutable HXMLElement myRoot;
        ElementDocument myDocument;
    };

}
