//
//  XmlReader.cpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/3/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "XmlReader.hpp"
#include "tinyxml2.h"
#include <sstream>

using namespace std;

namespace Xml
{
    HElement Reader::loadXml(stringstream& ss)
    {
        static tinyxml2::XMLDocument xmlDocument;
        const auto& str = ss.str();
        auto result = xmlDocument.Parse( str.c_str() );
        if ( result == tinyxml2::XML_SUCCESS )
        {
            return make_HElement( xmlDocument.RootElement() );
        }
        else
        {
            throw runtime_error( "failed to parse XML input" );
        }
    }
    
    HElement Reader::make_HElement(HXMLNode root)
    {
        return make_shared<Element>( root );
    }
}
