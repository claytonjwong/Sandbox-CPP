//
//  VectorGraphic.cpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/16/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <exception>
#include <list>
#include "VectorGraphic.hpp"
#include "Point.hpp"

namespace VG {
    
    Point VectorGraphic::getPoint(int index) const {
        if (index<0 || index>=myPointCnt)
            throw std::out_of_range{"invalid index"};
        for (auto& p: myPoints)
            if (index==0)
                return Point{p.getX(),p.getY()};
            else
                --index;
        return Point{0,0}; // should never reach here
    }
    
    bool VectorGraphic::operator==(const VectorGraphic& rhs){
        if (getPointCount()!=rhs.getPointCount())
            return false;
        if (myShapeIsOpen!=rhs.myShapeIsOpen)
            return false;
        return equal(myPoints.begin(),myPoints.end(),rhs.myPoints.begin());
    }
    
    bool VectorGraphic::operator!=(const VectorGraphic& rhs){
        return !(*this==rhs);
    }
    
    void VectorGraphic::addPoint(Point&& rhs){
        myPoints.emplace_back(std::move(rhs));
        ++myPointCnt;
    }
    
    void VectorGraphic::erasePoint(int index){
        if (index<0 || index>=myPointCnt)
            throw std::out_of_range{"invalid index"};
        auto itr=myPoints.begin();
        advance(itr,index);
        myPoints.erase(itr);
        --myPointCnt;
    }
    
    void VectorGraphic::removePoint(const Point& rhs){
        for (auto itr=myPoints.begin(); itr!=myPoints.end(); ++itr)
            if (*itr==rhs){
                myPoints.erase(itr);
                --myPointCnt;
                return;
            }
    }
}
