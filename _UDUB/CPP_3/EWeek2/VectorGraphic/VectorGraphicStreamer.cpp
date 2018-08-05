//
//  VectorGraphicStreamer.cpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/16/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "VectorGraphicStreamer.hpp"
#include "VectorGraphic.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

namespace VG
{    
    VectorGraphic VectorGraphicStreamer::getVectorGraphicFromFile(const std::string& filename)
    {
        auto ss = getStreamFromFile( filename );
        auto root = getHandleFromStream( ss );
        auto vg = getVectorGraphicFromHandle( root );
        return vg;
    }
    
    void VectorGraphicStreamer::setVectorGraphicToFile(const VectorGraphic& vg, const std::string& filename)
    {
        auto root = getHandleFromVectorGraphic( vg );
        auto ss = getStreamFromHandle( root );
        writeToFileFromStream( filename, ss );
    }

    stringstream VectorGraphicStreamer::getStreamFromFile(const string& filename)
    {
        stringstream ss;
        ifstream fin{ filename };
        if ( fin )
        {
            ss << fin.rdbuf();
        }
        else
        {
            throw invalid_argument( "input file not found" );
        }
        return ss;
    }
    
    Xml::HElement VectorGraphicStreamer::getHandleFromStream(std::stringstream& ss)
    {
        auto root = Xml::Reader::loadXml( ss );
        return root;
    }
    
    VectorGraphic VectorGraphicStreamer::getVectorGraphicFromHandle(const Xml::HElement root)
    {
        VectorGraphic vg;
        if ( root != nullptr && root->getName() == "VectorGraphic" )
        {
            for ( const auto& attribute: root->getAttributes() )
            {
                auto name = attribute.first;
                auto value = attribute.second;
                
                if ( name == "closed" )
                {
                    if ( value == "true" )
                    {
                        vg.closeShape();
                    }
                    else
                    {
                        vg.openShape();
                    }
                }
            }
            
            for ( const auto& child: root->getChildElements() )
            {
                auto name = child->getName();
                if ( name == "Point" )
                {
                    auto x = stoi(  child->getAttribute( "x" )  );
                    auto y = stoi(  child->getAttribute( "y" )  );
                    vg.addPoint(  Point{ x, y }  );
                }
            }
        }
        return vg;
    }

    Xml::HElement VectorGraphicStreamer::getHandleFromVectorGraphic(const VectorGraphic& vg)
    {
        auto root = Xml::Writer::make_HElement( vg );
        return root;
    }
    
    stringstream VectorGraphicStreamer::getStreamFromHandle(const Xml::HElement root)
    {
        stringstream ss;
        Xml::Writer::writeXml( root, ss );
        return ss;
    }
    
    void VectorGraphicStreamer::writeToFileFromStream(const std::string& filename, std::stringstream& ss)
    {
        ofstream fout{ filename };
        if ( fout )
        {
            fout << ss.rdbuf();
        }
        else
        {
            throw invalid_argument( "output file not found" );
        }
    }
}
