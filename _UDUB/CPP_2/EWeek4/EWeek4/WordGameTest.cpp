//
//  WordGameTest.cpp
//  EWeek4
//
//  Created by CLAYTON WONG on 5/22/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "TestHarness.h"
#include "WordGame.hpp"

#define WORD_GAME__DEBUG 1

#if !WORD_GAME__DEBUG
TEST(run,WordGame){ // input for rows/cols/len via console input
    WordGame wg;
    wg.Run();
}
#endif

#if WORD_GAME__DEBUG
TEST(special_4x4,WordGame){ // special 4x4 board for grading this assignment
    
    WordGame wg;
    
    int rows=4, cols=4, len=9;

    int beg=(int)clock();
    //
    // let M be the # rows in the board
    // let N be the # cols in the board
    // let K be the maximum length of the word to search for
    // let D be the amount of words in the dictionary
    //
    // then the bigO asymptotic bounds are:
    //
    // O(M*N*8^k) time
    //
    // O(D+K) space
    //
    // cw: Question -- is this correct?  this program takes between 1 and 2 seconds
    // to find all words of max size 9 in 4x4 board
    //
    
    wg.Run(rows,cols,len,true); // completes execution in about 1 second
    
    int end=(int)clock();
    int time=(end-beg)/double(CLOCKS_PER_SEC)*1000;
    std::cout << "Completed execution in " << time << " milliseconds!" << std::endl;
}
#endif

