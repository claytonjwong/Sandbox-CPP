//
//  Parse.hpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/11/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef Parse_hpp
#define Parse_hpp

#include <vector>
#include <string>
#include "Token.hpp"

namespace VG{
    class Parse {
    public:
        Parse()=delete;
        static const std::string NODE_VG;
        static const std::string NODE_PT;
        static const std::string ATTR_CLOSED;
        static const std::string ATTR_COORD__X;
        static const std::string ATTR_COORD__Y;
        static void trim(std::string& s, const std::string& chars=" \t\n");
        static void eat(std::istringstream& is, const std::string& chars=" \t\n");
        static Token tokenize(const std::string& str);
        static std::pair<std::string,std::string> to_keyval(const std::string& attribute);
        //static std::pair<std::string,std::string> getKeyAndValue(const std::string& attribute);
    };
}

#endif /* Parse_hpp */
