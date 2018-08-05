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
        
        PlacedGraphic(const VG::Point&& point, const VG::HVectorGraphic& vg)
        : myPlacementPoint{ point }, myGraphic{ *vg } {}

        VG::Point getPlacementPoint() const noexcept;
        const VG::VectorGraphic& getGraphic() const noexcept;
        
    private:
        
        const VG::Point myPlacementPoint;
        const VG::VectorGraphic& myGraphic;
        
    };
}
