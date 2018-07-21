//
//  VectorGraphicStreamer.cpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/16/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <fstream>
#include <sstream>
#include "VectorGraphicStreamer.hpp"
#include "VectorGraphic.hpp"
#include "Parse.hpp"

using namespace std;

namespace VG {
    
    VectorGraphic VectorGraphicStreamer::fromFile(const string& filename){
        ifstream fin(filename);
        stringstream ss;
        if (fin){
            ss << fin.rdbuf();
            return VectorGraphicStreamer::fromXml(ss);
        } else {
            throw invalid_argument("input file not found");
        }
    }
    
    VectorGraphic VectorGraphicStreamer::fromXml(stringstream& ss){
        return Parse::tokenize(ss);
    }
    
    void VectorGraphicStreamer::toFile(const string& filename, const VectorGraphic& vg){
        stringstream ss;
        ofstream fout(filename);
        VectorGraphicStreamer::toXml(vg, ss);
        if (fout){
            fout << ss.rdbuf();
        } else {
            throw invalid_argument("output file not found");
        }
    }
    
    void VectorGraphicStreamer::toXml(const VectorGraphic& vg, stringstream& ss){
        Parse::serialize(vg,ss);
    }
}
