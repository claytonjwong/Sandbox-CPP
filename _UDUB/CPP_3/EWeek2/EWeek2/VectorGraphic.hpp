//
//  VectorGraphic.hpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/16/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include <vector>
#include "Point.hpp"

namespace VG {
    
    using Points = std::vector<Point>;
    
    class VectorGraphic {
    public:
        VectorGraphic()=default;
        ~VectorGraphic()=default;
        VectorGraphic(VectorGraphic& src)=default;
        VectorGraphic(VectorGraphic&& src)=default;
        VectorGraphic& operator=(VectorGraphic& rhs)=default;
        VectorGraphic& operator=(VectorGraphic&& rhs)=default;

        const Point& getPoint(int index) const;
        size_t getPointCount() const noexcept { return myPoints.size(); }
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
        Points myPoints;
        bool myShapeIsOpen=false;
    };
    
    std::ostream& operator<<(std::ostream& os, const VectorGraphic& rhs);
}

