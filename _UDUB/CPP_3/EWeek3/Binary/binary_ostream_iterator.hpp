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
    template <class T, class charT=char, class traits=std::char_traits<charT> >
    class binary_ostream_iterator :
    public std::iterator<std::output_iterator_tag, void, void, void, void>
    {
    public:
    
      using ostream_type = std::basic_ostream<charT,traits>;
      binary_ostream_iterator(ostream_type& s) :
      out_stream{ &s }
      {
      }

      binary_ostream_iterator<T,charT,traits>& operator= (const T& value) {
        *out_stream << value;
        return *this;
      }

      binary_ostream_iterator<T,charT,traits>& operator*() { return *this; }
      binary_ostream_iterator<T,charT,traits>& operator++() { return *this; }
      binary_ostream_iterator<T,charT,traits>& operator++(int) { return *this; }

    private:
    
      std::basic_ostream<charT,traits>* out_stream;

    };
}
