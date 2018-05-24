//
//  BoardInitializerTest.cpp
//  EWeek4
//
//  Created by CLAYTON WONG on 5/23/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <stdio.h>
#include "TestHarness.h"
#include "BoardInitializer.hpp"
#include "Board.hpp"

TEST(_1x1,BoardInitializer){
    int rows=1,cols=1;
    Board boardObject(rows,cols);
    auto board=boardObject.GetBoard();
    CHECK(board.size()==rows);
    for (const auto& row: board)
        CHECK(row.size()==cols);
}

TEST(_2x3,BoardInitializer){
    int rows=2,cols=3;
    Board boardObject(rows,cols);
    auto board=boardObject.GetBoard();
    CHECK(board.size()==rows);
    for (const auto& row: board)
        CHECK(row.size()==cols);
}

TEST(_5x8,BoardInitializer){
    int rows=5,cols=8;
    Board boardObject(rows,cols);
    auto board=boardObject.GetBoard();
    CHECK(board.size()==rows);
    for (const auto& row: board)
        CHECK(row.size()==cols);
}

TEST(_4x4,BoardInitializer){ // special board for grading this assignment
    int rows=4,cols=4;
    Board boardObject(rows,cols);
    auto board=boardObject.GetBoard();
    CHECK(board.size()==rows);
    for (const auto& row: board)
        CHECK(row.size()==cols);
    CHECK(board[0]=="apex");
    CHECK(board[1]=="nots");
    CHECK(board[2]=="etin");
    CHECK(board[3]=="ryeg");
}
