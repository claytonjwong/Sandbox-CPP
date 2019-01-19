#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <iomanip>


using namespace std;


int main() try
{

#ifdef _WIN32
    cout << "stdin:  " << _isatty( _fileno( stdin ) )  << endl
         << "stdout: " << _isatty( _fileno( stdout ) ) << endl
         << "stderr: " << _isatty( _fileno( stderr ) ) << endl;
#else
    cout << "stdin:  " << isatty( fileno( stdin ) )  << endl
         << "stdout: " << isatty( fileno( stdout ) ) << endl
         << "stderr: " << isatty( fileno( stderr ) ) << endl;
#endif

    return 0;
}
catch( exception& e )
{
    cerr << e.what() << endl;
    return -1;
}
