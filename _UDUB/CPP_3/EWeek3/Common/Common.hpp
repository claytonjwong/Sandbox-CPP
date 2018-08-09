//
//  Common.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/9/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

template <typename T>
void verifyEquality ( const T& expected, const T& actual, const char* failure)
{
    if (  !( expected == actual )  )
    {
        throw std::runtime_error{ failure };
    }
}
