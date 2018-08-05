//
//  PlacedGraphic.hpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/4/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Point.hpp"
#include "VectorGraphic.hpp"

namespace Framework
{
    class PlacedGraphic
    {
    public:
        
//        PlacedGraphic()=default; // TODO change VG::VectorGraphic& myGraphic; to work for 2 TCs
                                   // this means remove the reference, dummmy!  Use ptr instead?

        PlacedGraphic(const VG::Point&& point, const VG::HVectorGraphic& vg)
        : myPlacementPoint{ point }, myGraphic{ vg.get() } {}
        
        ~PlacedGraphic()=default;
        
        PlacedGraphic(const PlacedGraphic& src)=default;
        PlacedGraphic(PlacedGraphic&& src)=default;
        
        PlacedGraphic& operator=(const PlacedGraphic& rhs)=default;
        PlacedGraphic& operator=(PlacedGraphic&& rhs)=default;

        VG::Point getPlacementPoint() const noexcept;
        const VG::VectorGraphic& getGraphic() const noexcept;
    
        void setPlacementPoint(const VG::Point&& point) noexcept;
    
    private:
        
        VG::Point myPlacementPoint;
        VG::VectorGraphic* myGraphic;
        
    };
}
