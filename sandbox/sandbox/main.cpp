#include <iostream>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

#define P first
#define S second
using PII=pair<int,int>;
using QPII=queue<PII>;
class Solution {
    struct hash { size_t operator()(const PII& x) const { return x.P*100000+x.S; } };
public:
    int racecar(int T, QPII q=QPII({make_pair(0,1)})) {
        unordered_set<PII, hash> v({q.front()});
        for (int d=0,N=(int)q.size(); ;++d,N=(int)q.size()) while (N--){ // process all N nodes at each depth d
            auto x=q.front(); q.pop();
            if (x.P==T) return d;
            auto A=make_pair(x.P + x.S,x.S * 2);
            if (!v.count(A) && abs(A.P - T) < T){ // prune A by position
                q.push(A);
                v.insert(A);
            }
            auto R=make_pair(x.P,(x.S > 0) ? -1 : 1);
            if (!v.count(R)){
                q.push(R);
                v.insert(R);
            }
        }
        return -1;
    }
};

int main(){
    
    
    
    return 0;
}
