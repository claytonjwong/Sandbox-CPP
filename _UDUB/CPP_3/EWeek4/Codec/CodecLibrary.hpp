//
//  CodecLibrary.hpp
//  EWeek4
//
//  Created by CLAYTON WONG on 8/31/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "IBitmapEncoder.hpp"
#include "IBitmapDecoder.hpp"

namespace Codec
{
    class CodecLibrary
    {
    public:
        
        CodecLibrary ( ) = default;
        
        CodecLibrary ( const CodecLibrary& src ) = default;
        CodecLibrary ( CodecLibrary&& src ) = default;
        
        CodecLibrary& operator= ( const CodecLibrary& rhs ) = default;
        CodecLibrary& operator= ( CodecLibrary&& rhs ) = default;
        
        void registerEncoder ( const HBitmapEncoder& encoder )
        {
            myEncoder = encoder;
        }
        
        void registerDecoder ( const HBitmapDecoder& decoder )
        {
            myDecoder = decoder;
        }
        
    private:
    
        HBitmapEncoder myEncoder;
        HBitmapDecoder myDecoder;
    };
}
