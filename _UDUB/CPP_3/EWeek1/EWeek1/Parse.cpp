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

using namespace std;

namespace VG {
    
    const std::string Parse::NODE_VG="VectorGraphic";
    const std::string Parse::NODE_PT="Point";
    const std::string Parse::ATTR_CLOSED="closed";
    const std::string Parse::ATTR_COORD__X="x";
    const std::string Parse::ATTR_COORD__Y="y";
    
    void Parse::trim(string& str, const string& chars){
        unordered_set<char> exclude{chars.begin(),chars.end()};
        str.erase(remove_if(str.begin(),str.end(),
                            [&](int val){
                                return exclude.find(val)!=exclude.end();
                            }),str.end());
    }

    void Parse::eat(istringstream& is, const string& chars){
        unordered_set<char> exclude{chars.begin(),chars.end()};
        while (is.peek()!=EOF && exclude.find(is.peek())!=exclude.end())
            is.ignore();
    }

    pair<string,string> Parse::to_keyval(const string& attribute){
        pair<string,string> ans;
        regex rex("^(\\S+)=\"(\\S+)\"$");
        smatch found;
        if (regex_match(attribute,found,rex)){
            ans.first=found[1];
            ans.second=found[2];
        }
        return ans;
    }
    
    //
    // hardcoded junk code (to be replaced with proper XML parser in real-world)
    //
    Token Parse::tokenize(const string& str){
        Token tok;
        regex rex("^(<\\/*)(\\S+)\\s*(\\S+=\"\\S+\")*\\s*(\\S+=\"\\S+\")*(\\/*>)$");
        smatch found;
        if (regex_match(str,found,rex)){
            tok.orig=found[0];
            tok.beg=found[1];
            tok.name=found[2];
            if (!found[3].str().empty())
                tok.attributes.push_back(found[3]);
            if (!found[4].str().empty())
                tok.attributes.push_back(found[4]);
            tok.end=found[5];
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
    
    pair<string,string> to_keyval(const string& attribute){
        pair<string,string> res;
        regex rex("^(\\S+)=\"(\\S+)\"$");
        smatch found;
        if (regex_match(attribute,found,rex)){
            res.first=found[1];
            res.second=found[2];
        }
        return res;
    }
}

