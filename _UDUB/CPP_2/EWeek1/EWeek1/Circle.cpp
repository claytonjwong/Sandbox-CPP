//
//  Circle.cpp
//  EWeek1
//
//  Created by CLAYTON WONG on 4/25/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include "Circle.h"

Circle::Circle( int radius,
       int xCoord, int yCoord,
       const char * name )
: mXCoord{xCoord},mYCoord{yCoord},mRadius{radius}{
    mName=new char[Circle::MAX_NAME_SIZE];
    mName[0]='\0';
    if (name)
        strlcpy(mName,name,Circle::MAX_NAME_SIZE);
}

Circle::~Circle(){
    delete[] mName;
}

Circle::Circle(const Circle& rhs)
: Circle(rhs.mRadius,rhs.mXCoord,rhs.mYCoord,rhs.mName) {}

Circle& Circle::operator=(const Circle& rhs){
    if (*this==rhs) return *this;
    mRadius=rhs.mRadius;
    mXCoord=rhs.mXCoord;
    mYCoord=rhs.mYCoord;
    strlcpy(mName,rhs.mName,Circle::MAX_NAME_SIZE);
    return *this;
}

void Circle::setName(const char* name){
    if (name==nullptr)
        name=nullptr;
    else
        strlcpy(mName, name, sizeof(mName));
}

bool Circle::operator==(const Circle& rhs){
    if (mRadius==rhs.mRadius && mXCoord==rhs.mXCoord && mYCoord==rhs.mYCoord
        && strncmp(mName,rhs.getName(),Circle::MAX_NAME_SIZE)==0) return true;
    return false;
}

bool Circle::operator!=(const Circle& rhs){
    return !(*this==rhs);
}

Circle& Circle::operator++(){
    ++mRadius;
    return *this;
}

Circle Circle::operator++(int){
    Circle c(*this);
    ++mRadius;
    return c;
}

Circle operator+(const Circle& lhs, const Circle& rhs){
    return std::move(Circle(lhs.getRadius()+rhs.getRadius()));
}

std::ostream& operator<<(std::ostream& os, const Circle& rhs){
    os << "(n=\"" << rhs.mName << "\",r=" << rhs.mRadius
    << ",x=" << rhs.mXCoord << ",y=" << rhs.mYCoord << ")";
    return os;
}


