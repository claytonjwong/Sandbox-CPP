//
//  XmlWriter.cpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/4/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//


#include "XmlWriter.hpp"

namespace Xml
{
    void Writer::writeXml(HElement root, ostream& os, int&& depth)
    {
        if ( root != nullptr )
        {
            writeXmlNodeHead( root, os, depth );
            
            for ( const auto& child: root->getChildElements() )
            {
                writeXml( child, os, ( depth + 1 ) );
            }
            
            writeXmlNodeTail( root, os, depth );
        }
    }
    
    void Writer::writeXmlNodeHead(HElement root, ostream& os, int depth)
    {
        writeLeadingWhitespace( os, depth );
        
        os << "<" << root->getName();
    
        for ( const auto& attribute: root->getAttributes())
        {
            auto name = attribute.first;
            auto value = attribute.second;
            
            os << " " << name << "=\"" << value << "\"";
        }
        
        os << ">" << endl;
    }
    
    void Writer::writeXmlNodeTail(HElement root, ostream& os, int depth)
    {
        writeLeadingWhitespace( os, depth );
        
        os << "</" << root->getName() << ">" << endl;
    }

    void Writer::writeLeadingWhitespace(ostream& os, int depth)
    {
        string whitespace( static_cast<size_t>( depth << 1 ), ' ' );
        
        os << whitespace;
    }
}
