/*
 
 Rank           Name            Score	Finish Time 	Q1 (2)      Q2 (5)      Q3 (7)      Q4 (7)
 1134 / 2573	claytonjwong 	2       0:05:43         0:05:43
 
 
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int cnt=0;
        set<int> jewel(J.begin(),J.end());
        for (const auto& s: S) if (jewel.find(s)!=jewel.end()) ++cnt;
        return cnt;
    }
};
*/

/*
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int global=0,local=0;
        for (int i=1; i<A.size(); ++i)
            if (A[i-1]>A[i]) ++local;
        for (int i=0; i<A.size(); ++i)
            for (int j=i+1; j<A.size(); ++j)
                if (A[i]>A[j] && ++global>local) return false;
        return global==local;
    }
};
*/




/*
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int n=(int)stations.size();
        vector<double> dist(n,0.0);
        for (int i=1; i<n; ++i){
            dist[i-1]=double(stations[i]-stations[i-1]);
        }
        for (int i=0; i<K; ++i){
            auto maxd=max_element(dist.begin(),dist.end());
            *maxd/=2;
        }
        return *max_element(dist.begin(),dist.end());
    }
};

 */


int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    
    cout << s.numJewelsInStones("z", "ZZ") << endl;
    */
    
    /*
    Solution s;
    vector<int> v { 1,0,2 };
    cout << s.isIdealPermutation(v) << endl;
    */
    
    /*
    Solution solution;
    vector<int> s { 10,19,25,27,56,63,70,87,96,97 };
    int k=3;
    cout << solution.minmaxGasDist(s, k) << endl;
    */
    
    return 0;
}
