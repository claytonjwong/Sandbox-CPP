//
//  Queue.hpp
//  EWeek5
//
//  Created by CLAYTON WONG on 6/1/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include <memory>
#include <exception>
#include <numeric>

class QueueException : public std::exception {
public:
    QueueException(const char* info) : myInfo{info} {}
    virtual const char* what() const throw() { return myInfo; }
private:
    const char* myInfo;
};

struct QueueFullException : public QueueException {
    QueueFullException(const char* info) : QueueException{info} {}
};

struct QueueEmptyException : public QueueException {
    QueueEmptyException(const char* info) : QueueException{info} {}
};

//
// Node is used as the queue's internal linked list container element
//
template <typename T>
struct Node {
    T val;
    std::shared_ptr<Node> prev, next;
    Node() : prev{nullptr}, next{nullptr} {}
    Node(T v) : val{v}, prev{nullptr}, next{nullptr} {}
};

//
// use template hoisting to factor out non-template-specifics
// this helps to avoid code bloat for multiple different types of T used
//
class QueueBase {
public:
    size_t size() const noexcept { return mySize; };
    bool empty() const noexcept { return size()==0; };
    
    void incrementSize() { ++mySize; }
    void decrementSize() { --mySize; }
    
private:
    size_t mySize=0;
};

//
// Queue container is implemented as linked list
//
//
// * push onto the back and pop from the front for first-in-first-out order
//
// * holds up to maximum of std::numeric_limits<std::size_t>::max()-1 items
//
// * implemented as a doubly linked list for efficient push()/pop()
//
// NOTE: I chose to use a linked list here since I have already created basically the same
// exact array based queue data structure in Assignment #5 of the previous C++ Intro course (CPROGRM 711 A)
// https://canvas.uw.edu/courses/1177926/assignments/3927356?module_item_id=7889539
//
template <typename T>
class Queue : public QueueBase {
public:
    Queue() : myBack{std::make_shared<Node<T>>()}, myFront{std::make_shared<Node<T>>()} {
        myBack->next=myFront;
        myFront->prev=myBack;
    }
    
    T front() const;
    
    void push(T x);
    void pop();
    
private:
    std::shared_ptr<Node<T>> myBack,myFront; // sentinels with dependency on q size
    //
    // Each sentinel can be uniquely identified as being the only nodes
    // in the linked list which contain a nullptr for either prev xor next
    // i.e. myBack->prev==nullptr && myFront->next==nullptr
    // all other nodes are inserted between these sentinels.
    // Now in this code I never check for these conditions for any operation
    // instead I rely on the q size to ensure these terminals work as expected
    // with these operations.  This may or may not be a good design decision.
    // The pros are that it is more efficient without these checks in place.
    // The cons are that if the size is incorrect (off by one or more),
    // then these operations may attempt to dereference the nullptr
    //
};

template <typename T>
T Queue<T>::front() const {
    if (empty())
        throw QueueEmptyException(__PRETTY_FUNCTION__);
    return myFront->prev->val;
}

template <typename T>
void Queue<T>::push(T x) {
    if (size()==std::numeric_limits<std::size_t>::max())
        throw QueueFullException(__PRETTY_FUNCTION__);
    auto node=std::make_shared<Node<T>>(x);
    node->prev=myBack;
    node->next=myBack->next;
    myBack->next=node;
    node->next->prev=node;
    incrementSize();
}

template <typename T>
void Queue<T>::pop() {
    if (empty())
        throw QueueEmptyException(__PRETTY_FUNCTION__);
    auto node=myFront->prev;
    myFront->prev=myFront->prev->prev;
    myFront->prev->next=myFront;
    node->next=nullptr;
    node->prev=nullptr;
    decrementSize();
}
