//
//  WordGameTest.cpp
//  EWeek4
//
//  Created by CLAYTON WONG on 5/22/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <stdio.h>
#include "TestHarness.h"
#include "WordGame.hpp"

/*
TEST(run,WordGame){
    WordGame wg;
    wg.Run();
    
}
*/

TEST(special_4x4,WordGame){
    WordGame wg;
    wg.Run(4,4,4);
}
