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
    Point PlacedGraphic::getPlacementPoint() const noexcept
    {
        return myPlacementPoint;
    }
    
    const VG::VectorGraphic& PlacedGraphic::getGraphic() const noexcept
    {
        return myGraphic;
    }
}
