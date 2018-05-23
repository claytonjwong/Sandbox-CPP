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
    void Run() {
        int boardSize, maxWordLength;
        std::cout << "Enter size of board: ";
        std::cin >> boardSize;
        assert(boardSize>0);
        std::cout << "Enter max word length: ";
        std::cin >> maxWordLength;
        assert(maxWordLength>0);
        Run(boardSize,maxWordLength);
    }
    void Run(int sz, int len){
        Board board(sz);
        Dictionary dic("WordsList.txt");
        WordFinder wf(board,dic,len);
        auto res=wf.FindWords();
    }
};

#endif /* WordGame_hpp */
