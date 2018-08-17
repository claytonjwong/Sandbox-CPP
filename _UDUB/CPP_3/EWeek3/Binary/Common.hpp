//
//  Common.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include <stdexcept>

namespace Binary
{

    template <typename T>
    void verifyEquality ( const T& expected, const T& actual, const char* failure )
    {
        if (  !( expected == actual )  )
        {
            throw std::runtime_error{ failure };
        }
    }
    
    
    enum class Endianness
    {
        Dynamic,
        Little,
        Big
    };
    

    static bool IS__LITTLE__ENDIAN ()
    {
        union
        {
            uint16_t word;
            uint8_t byte[2];
            
        } data{ 0xFF00 };
        
        return data.byte[1] == 0x00FF;
    }
    
    
    static bool IS__BIG__ENDIAN ()
    {
        return ! (  IS__LITTLE__ENDIAN()  );
    }
}
