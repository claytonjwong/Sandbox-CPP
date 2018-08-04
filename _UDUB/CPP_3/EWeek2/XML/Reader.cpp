//
//  XmlReader.cpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/3/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Reader.hpp"
#include "tinyxml2.h"
#include <sstream>

namespace Xml
{
    HElement Reader::loadXml(std::stringstream& ss)
    {
        static tinyxml2::XMLDocument xmlDocument;
        const auto& str=ss.str();
        auto result=xmlDocument.Parse(str.c_str());
        if ( result == tinyxml2::XML_SUCCESS )
        {
            return new Element{ xmlDocument.RootElement() };
        }
        else
        {
            throw std::runtime_error("failed to parse XML input");
        }
    }
}
