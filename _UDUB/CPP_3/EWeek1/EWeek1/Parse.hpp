//
//  Parse.hpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/11/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef Parse_hpp
#define Parse_hpp

#include <string>

class Parse {
public:
    static void trim(std::string& s, const std::string& chars=" \t\n");
    static void eat(std::istringstream& is, const std::string& chars=" \t\n");
};


#endif /* Parse_hpp */
