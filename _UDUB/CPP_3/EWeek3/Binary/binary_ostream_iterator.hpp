//
//  binary_ostream_iterator.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/13/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include <iterator>

namespace Binary
{
    template< class T, class charT = char, class traits = std::char_traits<charT> >
    class binary_ostream_iterator :
    public std::iterator< std::output_iterator_tag, void, void, void, void >
    {
    public:
    
      using ostream_type = std::basic_ostream< charT, traits >;
      using self_type = binary_ostream_iterator< T, charT, traits >;
      
      binary_ostream_iterator ( ostream_type& stream ) :
      myStream{ &stream }
      {
      }

      self_type& operator= (const T& value)
      {
        *myStream << value;
        return *this;
      }

      self_type& operator* () { return *this; }
      self_type& operator++ () { return *this; }
      self_type& operator++ (int) { return *this; }

    private:
    
      ostream_type* myStream;

    };
}
