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
        if (index<0 || index>=getPointCount())
            throw out_of_range{"invalid index"};
        return Point{myPoints[index].getX(),myPoints[index].getY()};
    }
    
    int VectorGraphic::getHeight() const noexcept { // lazy evaluation on-demand
        auto [minIt,maxIt]=minmax_element(myPoints.begin(),myPoints.end(),
            [](const Point& lhs, const Point& rhs) {return lhs.getY() < rhs.getY(); });
        return myPoints.empty() ? 0 : maxIt->getY() - minIt->getY();
    }
    
    int VectorGraphic::getWidth() const noexcept { // lazy evaluation on-demand
        auto [minIt,maxIt]=minmax_element(myPoints.begin(),myPoints.end(),
            [](const Point& lhs, const Point& rhs) {return lhs.getX() < rhs.getX(); });
        return myPoints.empty() ? 0 : maxIt->getX() - minIt->getX();
    }
    
    bool VectorGraphic::operator==(const VectorGraphic& rhs){
        return myPoints==rhs.myPoints && myShapeIsOpen==rhs.myShapeIsOpen;
    }
    
    bool VectorGraphic::operator!=(const VectorGraphic& rhs){
        return !(*this==rhs);
    }
    
    void VectorGraphic::addPoint(Point&& point){
        myPoints.emplace_back(std::forward<Point>(point));
    }
    
    void VectorGraphic::erasePoint(int index){
        if (index<0 || index>=getPointCount())
            throw out_of_range{"invalid index"};
        auto itr=myPoints.begin();
        advance(itr,index);
        myPoints.erase(itr);
    }
    
    void VectorGraphic::removePoint(const Point& rhs){
        for (auto itr=myPoints.begin(); itr!=myPoints.end(); ++itr)
            if (*itr==rhs){
                myPoints.erase(itr);
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
