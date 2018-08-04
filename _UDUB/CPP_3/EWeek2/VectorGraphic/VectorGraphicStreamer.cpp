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
#include <fstream>
#include <sstream>

using namespace std;

namespace VG {
    
    void VectorGraphicStreamer::fromFile(const string& filename, VectorGraphic& vg)
    {
        stringstream ss;
        ifstream fin{ filename };
        if ( fin )
        {
            ss << fin.rdbuf();
            fromStream( ss, vg );
        }
        else
        {
            throw invalid_argument( "input file not found" );
        }
    }
    
    void VectorGraphicStreamer::fromStream(stringstream& ss, VectorGraphic& vg)
    {
        auto handle = Xml::Reader::loadXml( ss );
        fromHandle( handle, vg );
    }
    
    void VectorGraphicStreamer::fromHandle(Xml::HElement handle, VectorGraphic& vg)
    {
        if ( handle->getName() == "VectorGraphic" )
        {
            for ( const auto& attribute: handle->getAttributes() )
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
            
            for ( const auto& child: handle->getChildElements() )
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
    }
    
    void VectorGraphicStreamer::toFile(const string& filename, const VectorGraphic& vg)
    {
        stringstream ss;
        ofstream fout{ filename };
        if ( fout )
        {
            toStream( ss, vg );
            fout << ss.rdbuf();
        }
        else
        {
            throw invalid_argument( "output file not found" );
        }
    }
    
    void VectorGraphicStreamer::toStream(stringstream& ss, const VectorGraphic& vg)
    {
        //Parse::serialize(ss,vg);
    }
}
