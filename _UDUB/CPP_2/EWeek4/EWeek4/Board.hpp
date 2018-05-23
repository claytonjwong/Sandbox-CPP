//
//  Board.hpp
//  EWeek4
//
//  Created by CLAYTON WONG on 5/22/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "BoardInitializer.hpp"

class Board {
public:
    Board(int size) : mySize{size} {
        myBoardInitializer.InitializeBoardDebug(myBoard, mySize);
    }
    int NumRows() const { return mySize; }
    int NumCols() const { return mySize; };
    
    const std::vector<std::string>& GetBoard() const {
        return myBoard;
    }
    
private:
    int mySize;
    std::vector<std::string> myBoard;
    BoardInitializer myBoardInitializer;
};

#endif /* Board_hpp */
