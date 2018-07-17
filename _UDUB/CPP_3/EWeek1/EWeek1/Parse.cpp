//
//  Parse.cpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/11/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Parse.hpp"
#include <string>
#include <unordered_set>
#include <iostream>
#include <sstream>

using namespace std;

void Parse::trim(string& str, const string& chars){
    unordered_set<char> exclude{chars.begin(),chars.end()};
    str.erase(remove_if(str.begin(),str.end(),
                        [&](int val){
                            return exclude.find(val)!=exclude.end();
                        }),str.end());
}

void Parse::eat(std::istringstream& is, const std::string& chars){
    unordered_set<char> exclude{chars.begin(),chars.end()};
    while (is.peek()!=EOF && exclude.find(is.peek())!=exclude.end())
        is.ignore();
}
