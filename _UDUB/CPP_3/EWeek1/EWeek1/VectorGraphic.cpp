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

using namespace std;

namespace VG {
    
    Point VectorGraphic::getPoint(int index) const { // O(n) find
        if (index<0 || index>=myPointCnt)
            throw out_of_range{"invalid index"};
        return Point{myPoints[index].getX(),myPoints[index].getY()};
    }
    
    int VectorGraphic::getHeight() const noexcept { // lazy evaluation on-demand
        if (myPointCnt==0)
            return 0;
        int minh=INT_MAX,maxh=INT_MIN;
        for (auto& p: myPoints){
            minh=min(minh,p.getY());
            maxh=max(maxh,p.getY());
        }
        return (int)abs(minh-maxh);
    }
    
    int VectorGraphic::getWidth() const noexcept { // lazy evaluation on-demand
        if (myPointCnt==0)
            return 0;
        int minw=INT_MAX,maxw=INT_MIN;
        for (auto& p: myPoints){
            minw=min(minw,p.getX());
            maxw=max(maxw,p.getX());
        }
        return (int)abs(minw-maxw);
    }
    
    bool VectorGraphic::operator==(const VectorGraphic& rhs){
        if (myPointCnt!=rhs.myPointCnt)
            return false;
        if (myShapeIsOpen!=rhs.myShapeIsOpen)
            return false;
        return equal(myPoints.begin(),myPoints.end(),rhs.myPoints.begin());
    }
    
    bool VectorGraphic::operator!=(const VectorGraphic& rhs){
        return !(*this==rhs);
    }
    
    void VectorGraphic::addPoint(Point&& rhs){ // O(1) insertion
        myPoints.emplace_back(std::move(rhs));
        ++myPointCnt;
    }
    
    void VectorGraphic::erasePoint(int index){ // O(n) removal
        if (index<0 || index>=myPointCnt)
            throw out_of_range{"invalid index"};
        auto itr=myPoints.begin();
        advance(itr,index);
        myPoints.erase(itr);
        --myPointCnt;
    }
    
    void VectorGraphic::removePoint(const Point& rhs){ // O(n) removal
        for (auto itr=myPoints.begin(); itr!=myPoints.end(); ++itr)
            if (*itr==rhs){
                myPoints.erase(itr);
                --myPointCnt;
                return;
            }
    }
    
    ostream& operator<<(ostream& os, const VectorGraphic& rhs){
        os << "<VectorGraphic closed=\"" << (rhs.isClosed() ? "true" : "false") << "\">" << endl;
        for (int i=0,N=(int)rhs.getPointCount(); i<N; ++i)
            os << "  " << rhs.getPoint(i) << endl;
        os << "</VectorGraphic>";
        return os;
    }
}
