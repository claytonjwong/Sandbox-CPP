//
//  VectorGraphic.hpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/16/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef VectorGraphic_hpp
#define VectorGraphic_hpp

#include <list>
#include "Point.hpp"

/*
 TEST(removePoint, VectorGraphic)
 {
 VG::VectorGraphic vg;
 vg.addPoint(VG::Point{1, 1});
 vg.addPoint(VG::Point{2, 2});
 vg.removePoint(VG::Point{1, 1});
 
 CHECK_EQUAL(1, vg.getPointCount());
 CHECK_EQUAL(VG::Point(2, 2), vg.getPoint(0));
 }
 */

namespace VG {
    class VectorGraphic {
    public:
        VectorGraphic()=default;
        ~VectorGraphic()=default;
        VectorGraphic(VectorGraphic& src)=default;
        VectorGraphic(VectorGraphic&& src)=default;
        VectorGraphic& operator=(VectorGraphic& rhs)=default;
        VectorGraphic& operator=(VectorGraphic&& rhs)=default;

        Point getPoint(int index) const;
        int getPointCount() const noexcept { return myPointCnt; }
        int getHeight() const noexcept;
        int getWidth() const noexcept;
        bool isClosed() const noexcept { return !isOpen(); }
        bool isOpen() const noexcept { return myShapeIsOpen; }
        bool operator==(const VectorGraphic& rhs);
        bool operator!=(const VectorGraphic& rhs);
        
        void addPoint(Point&& rhs);
        void erasePoint(int index);
        void removePoint(const Point& rhs);
        void openShape() noexcept { myShapeIsOpen=true; }
        void closeShape() noexcept { myShapeIsOpen=false; }
        
    private:
        int myPointCnt=0;
        std::list<Point> myPoints;
        bool myShapeIsOpen=false;
    };
    
}

#endif /* VectorGraphic_hpp */
