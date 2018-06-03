//
//  QueueTest.cpp
//  EWeek5
//
//  Created by CLAYTON WONG on 6/1/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <iostream>
#include "TestHarness.h"
#include "Queue.hpp"

using namespace std;

TEST(ctor,Queue){
    Queue<int> q;
    CHECK(q.size()==0);
    CHECK(q.empty());
}

TEST(pushPop,Queue){
    Queue<string> q;

    q.push("hi");
    CHECK(q.size()==1);
    CHECK(!q.empty());
    CHECK(q.front()=="hi");

    q.push("there");
    CHECK(q.size()==2);
    CHECK(!q.empty());
    CHECK(q.front()=="hi");

    q.push("how");
    CHECK(q.size()==3);
    CHECK(!q.empty());
    CHECK(q.front()=="hi");

    q.push("are");
    CHECK(q.size()==4);
    CHECK(!q.empty());
    CHECK(q.front()=="hi");

    q.push("you?");
    CHECK(q.size()==5);
    CHECK(!q.empty());
    CHECK(q.front()=="hi");
    
    
    q.pop();

    CHECK(q.size()==4);
    CHECK(!q.empty());
    CHECK(q.front()=="there");
    q.pop();
    
    
    CHECK(q.size()==3);
    CHECK(!q.empty());
    CHECK(q.front()=="how");
    q.pop();
    
    
    CHECK(q.size()==2);
    CHECK(!q.empty());
    CHECK(q.front()=="are");
    q.pop();
    
    
    CHECK(q.size()==1);
    CHECK(q.front()=="you?");

    q.pop();
    CHECK(q.empty());

}

TEST(exceptionEmptyFront,Queue){
    Queue<bool> q;
    try {
        q.front();
        CHECK(false); // should jump over this statement due to ex thrown
    } catch (const QueueEmptyException& e) {
        CHECK(true);
        cerr << "PASS! Expected exception via q.front(): " << e.what() << endl;
    }
}

TEST(exceptionEmptyPop,Queue){
    Queue<double> q;
    try {
        q.pop();
        CHECK(false); // should jump over this statement due to ex thrown
    } catch (const QueueEmptyException& e) {
        CHECK(true);
        cerr << "PASS! Expected exception via q.pop(): " << e.what() << endl;
    }
}
