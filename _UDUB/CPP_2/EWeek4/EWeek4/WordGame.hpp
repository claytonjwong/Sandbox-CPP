//
//  WordGame.hpp
//  EWeek4
//
//  Created by CLAYTON WONG on 5/22/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef WordGame_hpp
#define WordGame_hpp

#include <iostream>
#include <stdio.h>
#include "Board.hpp"
#include "BoardInitializer.hpp"
#include "WordFinder.hpp"

class WordGame {
public:
    void Run() const;
    void Run(int rows, int cols, int len) const;
};

#endif /* WordGame_hpp */
