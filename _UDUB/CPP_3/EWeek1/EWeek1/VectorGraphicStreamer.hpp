//
//  VectorGraphicStreamer.hpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/16/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef VectorGraphicStreamer_hpp
#define VectorGraphicStreamer_hpp

#include <sstream>
#include "VectorGraphic.hpp"

namespace VG {
    class VectorGraphicStreamer {
    public:
        static VectorGraphic fromXml(std::stringstream& sstr);
        static void toXml(std::stringstream& ss);
    };
}


#endif /* VectorGraphicStreamer_hpp */
