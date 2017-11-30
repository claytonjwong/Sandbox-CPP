/*
 
 Utility typedefs and defines for coding competitions
 
 */

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<pair<int,int>> VII;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)


template<class T> inline void umin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void umax(T &x, const T &y) { if (x<y) x=y; }

void printDP(vector<vector<int>>& dp){
    for (auto &&r: dp){
        for (auto &&c: r)
            cout << c;
        cout << endl;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
