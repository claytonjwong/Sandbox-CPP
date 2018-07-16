//
//  sort_test.cpp
//  CH02
//
//  Created by CLAYTON WONG on 7/13/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "sort.hpp"
#include "TestHarness.h"

using namespace std;

TEST (All,sort){
    const vector<int> CONST_A{9,6,3,4,8,2,0,1,5,7};
    vector<int> A,empty;
    
    A=CONST_A; CHECK(!is_sorted(A.begin(),A.end()));
    insertion_sort1(A);
    insertion_sort1(empty);
    CHECK(is_sorted(A.begin(), A.end()));
    
    A=CONST_A; CHECK(!is_sorted(A.begin(),A.end()));
    insertion_sort2(A);
    insertion_sort2(empty);
    CHECK(is_sorted(A.begin(), A.end()));
    
    A=CONST_A; CHECK(!is_sorted(A.begin(),A.end()));
    selection_sort1(A);
    selection_sort1(empty);
    CHECK(is_sorted(A.begin(), A.end()));
    
    A=CONST_A; CHECK(!is_sorted(A.begin(),A.end()));
    selection_sort2(A);
    selection_sort2(empty);
    CHECK(is_sorted(A.begin(), A.end()));
    
    A=CONST_A; CHECK(!is_sorted(A.begin(),A.end()));
    selection_sort3(A);
    selection_sort3(empty);
    CHECK(is_sorted(A.begin(), A.end()));
    
    A=CONST_A; CHECK(!is_sorted(A.begin(),A.end()));
    selection_sort4(A);
    selection_sort4(empty);
    CHECK(is_sorted(A.begin(), A.end()));

    A=CONST_A; CHECK(!is_sorted(A.begin(),A.end()));
    selection_sort5(A);
    selection_sort5(empty);
    CHECK(is_sorted(A.begin(), A.end()));

    A=CONST_A; CHECK(!is_sorted(A.begin(),A.end()));
    bubble_sort1(A);
    bubble_sort1(empty);
    CHECK(is_sorted(A.begin(), A.end()));

    A=CONST_A; CHECK(!is_sorted(A.begin(),A.end()));
    bubble_sort2(A);
    bubble_sort2(empty);
    CHECK(is_sorted(A.begin(), A.end()));

}
