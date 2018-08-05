//
//  VectorGraphicStreamer.hpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/16/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Element.hpp"
#include "VectorGraphic.hpp"
#include <sstream>

namespace VG {
    
    class VectorGraphicStreamer
    {
    public:
    
    /*
        static void fromFile(const std::string& filename, VectorGraphic& vg);
        static void toFile(const std::string& filename, const VectorGraphic& vg);
        
        static void fromStream(std::stringstream& sstr, VectorGraphic& vg);
        static void toStream(std::stringstream& sstr, const VectorGraphic& vg);
        
        
        static void fromHandle(Xml::HElement root, VectorGraphic& vg);
        
        static Xml::HElement getHandle(const VectorGraphic& vg);
        static void getStream(const std::string& filename, const Xml::HElement root);
        static void toFile(const std::string& filename, std::stringstream& ss);
    */
    
        static VectorGraphic getVectorGraphicFromFile(const std::string& filename);
        static void setVectorGraphicToFile(const VectorGraphic& vg, const std::string& filename);
    
        static std::stringstream getStreamFromFile(const std::string& filename);
        static Xml::HElement getHandleFromStream(std::stringstream& ss);
        static VectorGraphic getVectorGraphicFromHandle(const Xml::HElement root);
        
        static Xml::HElement getHandleFromVectorGraphic(const VectorGraphic& vg);
        static std::stringstream getStreamFromHandle(const Xml::HElement root);
        static void writeToFileFromStream(const std::string& filename, std::stringstream& ss);
    };
}


