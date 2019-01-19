#include "template.h"
#include <iostream>

using namespace std;

int main()
{
    messageTemplate< int > test{ "test", 69 };

    cout << test << endl;

    return 0;
}