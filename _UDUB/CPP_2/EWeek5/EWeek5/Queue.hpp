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

class ExceptionQueueEmpty : public std::exception {
public:
    ExceptionQueueEmpty(const char* info) : myInfo{info} {}
    virtual const char* what() const throw() { return myInfo; }
private:
    const char* myInfo;
};

template <typename T>
struct Node {
    T val;
    std::shared_ptr<Node> prev, next;
    Node() : prev{nullptr}, next{nullptr} {}
    Node(T v) : val{v}, prev{nullptr}, next{nullptr} {}
};

class QueueBase {
public:
    size_t size() const noexcept { return mySize; };
    bool empty() const noexcept { return size()==0; };
    
    void incrementSize() { ++mySize; }
    void decrementSize() { --mySize; }
    
private:
    size_t mySize=0;
};

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
    std::shared_ptr<Node<T>> myBack,myFront;
};

template <typename T>
T Queue<T>::front() const {
    if (empty())
        throw ExceptionQueueEmpty(__PRETTY_FUNCTION__);
    return myFront->prev->val;
}

template <typename T>
void Queue<T>::push(T x) {
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
        throw ExceptionQueueEmpty(__PRETTY_FUNCTION__);
    auto node=myFront->prev;
    myFront->prev=myFront->prev->prev;
    myFront->prev->next=myFront;
    node->next=nullptr;
    node->prev=nullptr;
    decrementSize();
}
