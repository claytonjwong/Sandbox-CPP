//
//  WordFinder.cpp
//  EWeek4
//
//  Created by CLAYTON WONG on 5/23/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "WordFinder.hpp"

TWordsList WordFinder::FindWords() const {
    TWordsList ans;
    
    return ans;
}

void WordFinder::go(int i, int j) {
    if (i<0||j<0||i>=myBoard.NumRows()||j>=myBoard.NumCols()) return;
    
}
