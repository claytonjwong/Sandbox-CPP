//
//  XmlWriter.cpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/4/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//


#include "XmlWriter.hpp"
#include "VectorGraphic.hpp"

using namespace std;

namespace Xml
{
    void Writer::writeXml(const HElement root, ostream& os, int&& depth) // default value depth=0
    {
        if ( root != nullptr )
        {
            writeXmlNodeHead( root, os, depth );
            
            for ( const auto& child: root->getChildElements() )
            {
                writeXml(  child, os, ( depth + 1 )  );
            }
            
            writeXmlNodeTail( root, os, depth );
        }
    }
    
    void Writer::writeXmlNodeHead(const HElement root, ostream& os, const int depth)
    {
        writeLeadingWhitespace( os, depth );
        
        os << "<" << root->getName();
    
        for ( const auto& attribute: root->getAttributes() )
        {
            auto name = attribute.first;
            auto value = attribute.second;
            
            os << " " << name << "=\"" << value << "\"";
        }
        
        os << ">" << endl;
    }
    
    void Writer::writeXmlNodeTail(const HElement root, ostream& os, const int depth)
    {
        writeLeadingWhitespace( os, depth );
        
        os << "</" << root->getName() << ">" << endl;
    }

    void Writer::writeLeadingWhitespace(ostream& os, const int depth)
    {
        //
        // leading whitespace indentation increases by 2 * depth
        //
        string whitespace(  static_cast<size_t>( depth << 1 ), 0x20  );
        
        os << whitespace;
    }
    
    const HElement Writer::make_HElement(const VG::VectorGraphic& vg)
    {
        HElement result = make_shared<Element>();
        auto root = result->xmlDocument.NewElement( "VectorGraphic" ); // TODO: expose API & update myRoot in there
        
        root->SetAttribute(  "closed", ( vg.isClosed() ? "true" : "false" )  );
        
        for (  int i=0, N=static_cast<int>( vg.getPointCount() ); i < N; ++i  )
        {
            auto point = vg.getPoint( i );
            auto node = result->xmlDocument.NewElement( "Point" );
            node->SetAttribute( "x", point.getX() );
            node->SetAttribute( "y", point.getY() );
            root->InsertEndChild( node );
        }
        
        result->xmlDocument.InsertFirstChild( root ); // TODO: expose API & update myRoot in there (continued)
        
        return result;
    }
}
