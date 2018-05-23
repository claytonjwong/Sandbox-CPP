//
//  BoardInitializer.cpp
//  EWeek4
//
//  Created by CLAYTON WONG on 5/22/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "BoardInitializer.hpp"
#include <vector>
#include <string>

using namespace std;

void BoardInitializer::InitializeBoardDebug(vector<string>& B, int N){
    if (N==1){
        vector<string> X{
            "a",
        };
        B.swap(X);
    }
    else if (N==2){
        vector<string> X{
            "ba",
            "tr",
        };
        B.swap(X);
    }
    else if (N==3){
        vector<string> X{
            "bac",
            "trk",
            "ape",
        };
        B.swap(X);
    }
    else if (N==4){
        vector<string> X{
            "apex",
            "nots",
            "etin",
            "ryeg",
        };
        B.swap(X);
    }
    else {
        vector<string> X{
            "baegs",
            "trhok",
            "apete",
            "loopd",
            "praio",
        };
        B.swap(X);
    }
}
