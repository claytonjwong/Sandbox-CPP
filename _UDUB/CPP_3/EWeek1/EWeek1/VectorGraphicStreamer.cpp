//
//  VectorGraphicStreamer.cpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/16/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <sstream>
#include "VectorGraphicStreamer.hpp"
#include "VectorGraphic.hpp"
#include "Parse.hpp"

using namespace std;

/*
 // C++11 has a new "raw string literal" that is useful for
 // embedding long strings in a file for testing. Previously
 // this would have to be done with a "stringification" macro:
 //   #define STR(a) #a
 
 
 
 TEST(fromXml, VectorGraphic)
 {
 std::stringstream sstr(VectorGraphicXml);
 
 auto vg = VG::VectorGraphicStreamer::fromXml(sstr);
 
 CHECK_EQUAL(true, vg.isClosed());
 CHECK_EQUAL(4, vg.getPointCount());
 CHECK_EQUAL(10, vg.getPoint(2).getX());
 CHECK_EQUAL(10, vg.getPoint(2).getY());
 }
 
 TEST(toXml, VectorGraphic)
 {
 VG::VectorGraphic vg1;
 vg1.addPoint(VG::Point(1, 1));
 vg1.addPoint(VG::Point(2, 2));
 vg1.addPoint(VG::Point(3, 3));
 
 std::stringstream sstr;
 VG::VectorGraphicStreamer::toXml(vg1, sstr);
 
 auto vg2 = VG::VectorGraphicStreamer::fromXml(sstr);
 
 CHECK(vg1 == vg2);
 }
 */

/*
 const std::string VectorGraphicXml = R"(
 <VectorGraphic closed="true">
 <Point x="0" y="0"/>
 <Point x="10" y="0">
 </Point>
 <Point x="10" y="10"/>
 <Point x="0" y="10"/>
 </VectorGraphic>
 )";
 */

//static void trim(std::string& s, const std::string& chars=" \t\n");

namespace VG {
    
    struct ExceptionFromXML : public exception {
        const char* what() const throw() {
            return "ExceptionFromXML";
        }
    };
    
    struct ExceptionToXML : public exception {
        const char* what() const throw() {
            return "ExceptionToXML";
        }
    };
    
    VectorGraphic VectorGraphicStreamer::fromXml(stringstream& input){
        VectorGraphic res;
        string line;
        while (getline(input,line)){
            if (line.empty()) continue;
            auto tok=Parse::tokenize(line);
            if (tok.name==Parse::NODE_VG){
                //
                // TODO handle open/closed nodes properly ( currently crash on "</VectorGraphic>" <-- closed element )
                //
                auto keyval=Parse::to_keyval(tok.attributes[0]);
                if (keyval.first==Parse::ATTR_CLOSED){
                    Parse::trim(keyval.second,"\"");
                    transform(keyval.second.begin(),keyval.second.end(),keyval.second.begin(),::tolower);
                    if (keyval.second=="true")
                        res.closeShape();
                    if (keyval.second=="false")
                        res.openShape();
                }
            }
        }
        return res;
    }
    
    void VectorGraphicStreamer::toXml(stringstream& ss){
        
    }
}
