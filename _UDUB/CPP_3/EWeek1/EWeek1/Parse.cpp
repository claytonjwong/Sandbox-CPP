//
//  Parse.cpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/11/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <string>
#include <unordered_set>
#include <iostream>
#include <sstream>
#include <regex>
#include "Parse.hpp"
#include "Token.hpp"
#include "VectorGraphic.hpp"

using namespace std;

namespace VG {
    
    const std::string Parse::NODE_VG="VectorGraphic";
    const std::string Parse::NODE_PT="Point";
    const std::string Parse::ATTR_CLOSED="closed";
    const std::string Parse::ATTR_COORD__X="x";
    const std::string Parse::ATTR_COORD__Y="y";
    
    void Parse::trim(string& str, const string& chars){
        try {
            unordered_set<char> exclude{chars.begin(),chars.end()};
            str.erase(remove_if(str.begin(),str.end(),
                                [&](int val){
                                    return exclude.find(val)!=exclude.end();
                                }),str.end());
        } catch (...) {
            throw ParseException();
        }
    }

    void Parse::eat(istringstream& is, const string& chars){
        try {
            unordered_set<char> exclude{chars.begin(),chars.end()};
            while (is.peek()!=EOF && exclude.find(is.peek())!=exclude.end())
                is.ignore();
        } catch (...) {
            throw ParseException();
        }
    }
    
    VectorGraphic Parse::tokenize(stringstream& ss){
        VectorGraphic res;
        try {
            string line;
            while (getline(ss,line)){
                if (!line.empty()){
                    auto tok=Parse::tokenize(line);
                    Parse::process_token(res,tok);
                }
            }
        } catch (...) {
            throw ParseException();
        }
        return res;
    }
    
    //
    // hardcoded junk code (to be replaced with proper XML parser in real-world)
    //
    // below this function are example contents of found's values per index [0:5]
    // when this function is invoked with each different string parameter value
    //
    Token Parse::tokenize(const string& str){
        Token tok;
        try {
            regex rex("^\\s*(<\\/*)(\\S+)\\s*(\\S+=\"\\S+\")*\\s*(\\S+=\"\\S+\")*(\\/*>)\\s*$");
            smatch found;
            cout << str << endl;
            if (regex_match(str,found,rex)){
                if (found.size()!=6)
                    throw ParseException();
                tok.orig=found[0];
                tok.beg=found[1];
                tok.name=found[2];
                if (!found[3].str().empty())
                    tok.attributes.push_back(found[3]);
                if (!found[4].str().empty())
                    tok.attributes.push_back(found[4]);
                tok.end=found[5];
            }
        } catch (...) {
            throw ParseException();
        }
        return tok;
    }
    /****************************************************************
     
     tokenize(<VectorGraphic closed="true">)
     0: <VectorGraphic closed="true">
     1: <
     2: VectorGraphic
     3: closed="true"
     4:
     5: >
     
     tokenize(<Point x="0" y="0"/>)
     0: <Point x="0" y="0"/>
     1: <
     2: Point
     3: x="0"
     4: y="0"
     5: />
     
     tokenize(<Point x="10" y="0">)
     0: <Point x="10" y="0">
     1: <
     2: Point
     3: x="10"
     4: y="0"
     5: >
     
     tokenize(</Point>)
     0: </Point>
     1: </
     2: Point
     3:
     4:
     5: >
     
     ****************************************************************/
    
    //
    // hardcoded junk code (to be replaced with proper XML parser in real-world)
    //
    // below this function are example contents of found's values per index [0:2]
    // when this function is invoked with each different string parameter value
    //
    pair<string,string> Parse::to_keyval(const string& attribute){
        pair<string,string> ans;
        try {
            regex rex("^\\s*(\\S+)=\"(\\S+)\"\\s*$");
            smatch found;
            if (!attribute.empty() && regex_match(attribute,found,rex)){
                ans.first=found[1];
                ans.second=found[2];
            }
        } catch (...) {
            throw ParseException();
        }
        return ans;
    }
    /****************************************************************
     
     to_keyval(closed="true")
     0: closed="true"
     1: closed
     2: true
     
     to_keyval(x="0")
     0: x="0"
     1: x
     2: 0
     
     to_keyval(y="0")
     0: y="0"
     1: y
     2: 0
     
     ****************************************************************/
    
     void Parse::process_token(VectorGraphic& vg, const Token& tok){
         try {
             if (tok.name==Parse::NODE_VG){
                 if (tok.isOpen()) {
                     auto attr=Parse::to_keyval(tok.attributes[0]);
                     if (attr.first==Parse::ATTR_CLOSED){
                         if (attr.second=="true")
                             vg.closeShape();
                         if (attr.second=="false")
                             vg.openShape();
                     }
                 }
             }
             else if (tok.name==Parse::NODE_PT){
                 if (tok.isOpen()){
                     auto attrX=Parse::to_keyval(tok.attributes[0]);
                     auto attrY=Parse::to_keyval(tok.attributes[1]);
                     vg.addPoint(Point{stoi(attrX.second),stoi(attrY.second)});
                 }
             }
         } catch (...) {
             throw ParseException();
         }
    }
    
    void Parse::serialize(const VectorGraphic& vg, stringstream& ss){
        try {
            ss.str("");
            ss << "<VectorGraphic closed=\"" << (vg.isClosed() ? "true" : "false") << "\">" << endl;
            for (int i=0,N=(int)vg.getPointCount(); i<N; ++i){
                auto pt=vg.getPoint(i);
                ss << "<Point x=\"" << pt.getX() << "\" y=\"" << pt.getY() << "\"/>" << endl;
            }
            ss << "</VectorGraphic>" << endl;
        } catch (...) {
            throw ParseException();
        }
    }
}

