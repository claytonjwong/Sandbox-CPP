//
//  WordFinder.cpp
//  EWeek4
//
//  Created by CLAYTON WONG on 5/23/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <unordered_set>
#include "WordFinder.hpp"

using namespace std;

TWordsList WordFinder::FindWords() {
    myWords.clear();
    for (int i=0; i<myBoard.NumRows(); ++i)
        for (int j=0; j<myBoard.NumCols(); ++j)
            go(i,j);
    return myWords;
}

void WordFinder::go(int i, int j, string str, unordered_set<int> visited) {
    if (i<0||j<0||i>=myBoard.NumRows()||j>=myBoard.NumCols()) return;
    if (!visited.insert(key(i,j)).second) return;
    str.push_back(myBoard[i][j]);
    if (str.size()<=myMaxLength){
        if (myDic.Contains(str))
            myWords.insert(str);
    }
    if (str.size()<myMaxLength){
        for (auto& dir: myDirs)
            go(i+dir.first,j+dir.second,str,visited);
    }
    visited.erase(key(i,j));
    str.pop_back();
}
