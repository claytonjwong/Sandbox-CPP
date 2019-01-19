#include "template.h"
#include <iostream>
#include <string>

using namespace std;

template class messageTemplate<int>;
template class messageTemplate<double>;
template class messageTemplate<std::string>;
template class messageTemplate<bool>;
