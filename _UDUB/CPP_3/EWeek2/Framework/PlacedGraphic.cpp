//
//  PlacedGraphic.cpp
//  EWeek2
//
//  Created by CLAYTON WONG on 8/4/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "PlacedGraphic.hpp"

using namespace VG;

namespace Framework
{
    PlacedGraphic::PlacedGraphic()
    : myPlacementPoint{ VG::Point{0,0} }, myGraphicHandle{ nullptr } {}
    
    PlacedGraphic::PlacedGraphic(const VG::Point&& point, const VG::HVectorGraphic& hvg)
    : myPlacementPoint{ point }, myGraphicHandle{ hvg } {}

    Point PlacedGraphic::getPlacementPoint() const noexcept
    {
        return myPlacementPoint;
    }
    
    const VG::VectorGraphic& PlacedGraphic::getGraphic() const noexcept
    {
        return *myGraphicHandle.get();
        
    }
    
    void PlacedGraphic::setPlacementPoint(const VG::Point&& point) noexcept
    {
        myPlacementPoint = point;
    }
    
    void PlacedGraphic::setGraphic(const VG::HVectorGraphic& hvg) noexcept
    {
        myGraphicHandle = hvg;
    }
}
