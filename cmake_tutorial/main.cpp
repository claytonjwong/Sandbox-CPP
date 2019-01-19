#include "config.h"
#ifdef USE_OUTPUT_FUNCTIONS
#include "output_version.hpp"
#endif
#include <iostream>


using namespace std;


int main()
{
    #ifdef USE_OUTPUT_FUNCTIONS
        output_version();
    #else
        cout << "Version: " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << endl;
    #endif

    return 0;
}