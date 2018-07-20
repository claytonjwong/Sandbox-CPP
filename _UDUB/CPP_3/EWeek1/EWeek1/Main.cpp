#include <iostream>
#include <fstream>
#include <sstream>
#include "TestHarness.h"
#include "VectorGraphicStreamer.hpp"

using namespace std;
using namespace VG;

int main(int argc, char *argv[])
{

	// random number generator used in some tests
	srand(::time_t(NULL));

    TestResult tr;
    TestRegistry::runAllTests(tr);

	// force console screen to hold
	char ch;
	std::cin >> ch;

/*
    if (argc!=3){
        cerr << "invalid params.  expected infile and outfile." << endl;
        return -1;
    }
    stringstream ss;
    string infile(argv[1]),outfile(argv[2]);
    {
        ifstream fin(infile);
        if (fin){
            ss << fin.rdbuf();
            auto vg=VectorGraphicStreamer::fromXml(ss);
        }
    }
    {
        ofstream fout(outfile);
        if (fout){
            fout << ss.rdbuf();
        }
    }
*/
    return 0;
}
