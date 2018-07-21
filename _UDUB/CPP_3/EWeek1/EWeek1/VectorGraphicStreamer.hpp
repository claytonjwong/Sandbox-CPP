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
        static VectorGraphic fromFile(const std::string& filename);
        static VectorGraphic fromXml(std::stringstream& sstr);
        static void toFile(const std::string& filename, const VectorGraphic& vg);
        static void toXml(const VectorGraphic& vg, std::stringstream& ss);
    };
}


#endif /* VectorGraphicStreamer_hpp */
