//
//  VectorGraphicStreamer.cpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/16/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <sstream>
#include "VectorGraphicStreamer.hpp"
#include "VectorGraphic.hpp"
#include "Parse.hpp"

using namespace std;

namespace VG {
    
    VectorGraphic VectorGraphicStreamer::fromXml(stringstream& ss){
        return Parse::tokenize(ss);
    }
    
    void VectorGraphicStreamer::toXml(const VectorGraphic& vg, stringstream& ss){
        Parse::serialize(vg,ss);
    }
}
