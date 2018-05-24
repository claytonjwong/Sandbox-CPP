//
//  WordGame.cpp
//  EWeek4
//
//  Created by CLAYTON WONG on 5/22/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "WordGame.hpp"
#include "Board.hpp"
#include "BoardInitializer.hpp"
#include "WordFinder.hpp"

using namespace std;

void WordGame::Run() const {
    int rows, cols, len;
    
    cout << "# rows: ";
    cin >> rows;
    assert(rows>0);
    
    cout << "# cols: ";
    cin >> cols;
    assert(cols>0);
    
    cout << "Max len: ";
    cin >> len;
    assert(len>0);
    
    Run(rows,cols,len);
}

void WordGame::Run(int rows, int cols, int len) const {
    Board board(rows,cols);
    Dictionary dic("WordsList.txt");
    WordFinder finder(board,dic,len);
    auto res=finder.FindWords();
    for (auto& x: res){
        cout << x << endl;
    }
}
