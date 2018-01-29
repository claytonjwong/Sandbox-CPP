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
#include <unordered_map>

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int cnt=0;
        unordered_map<char,bool> m;
        for (auto& j: J) m[j]=true;
        for (auto& s: S) if (m[s]) ++cnt;
        return cnt;
    }
};
 */

class SolutionTLE {
public:
    bool isIdealPermutation(vector<int>& A) {
        int global=0,local=0;
        for (int i=0; i<A.size()-1; ++i)
            if (A[i]>A[i+1]) ++local;
        for (int i=0; i<A.size()-1; ++i)
            for (int j=i+1; j<A.size(); ++j)
                if (A[i]>A[j] && ++global>local) return false;
        return global==local;
    }
};

/*
class Solution {
public:
    bool isIdealPermutation(vector<int>& A){
        int n=(int)A.size();
        vector<int> dp(n,INT_MAX);
        dp.back()=A.back();
        for (int i=n-2; i>=0; --i)
            dp[i]=min(A[i],dp[i+1]);
        for (int i=2; i<n; ++i)
            if (A[i-2] > dp[i])
                return false;
        return true;
    }
};
 */

/*
class Solution {
public:
    bool isIdealPermutation(vector<int>& A){
        int n=(int)A.size(),mini=A.back();
        for (int i=n-3; i>=0; --i){
            mini=min(mini,A[i+2]);
            if (A[i] > mini)
                return false;
        }
        return true;
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
#include <queue>

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        priority_queue<Interval> q;
        for (int i=1; i<stations.size(); ++i)
            q.push(Interval(stations[i]-stations[i-1]));
        double cutoff=double(stations.back()-stations[0]) / double(K);
        while(K){
            auto maxi=q.top();
            q.pop();
            do{
                maxi.currDist=maxi.origDist/(++maxi.stationCnt);
            }while(--K && ( maxi.currDist >= cutoff));
            q.push(maxi);
        }
        return q.top().currDist;
    }
private:
    class Interval{
    public:
        double origDist, currDist;
        int stationCnt;
        Interval(int dist) : origDist{double(dist)}, currDist{double(dist)}, stationCnt{1} {}
        bool operator<(const Interval& rhs) const { return currDist < rhs.currDist; }
    };
};

*/



#include <sstream>
#include <queue>
#include <unordered_map>

class Solution{
public:
    string reorganizeString(string S){
        unordered_map<char,int> m;
        for (const auto& c: S) ++m[c];
        priority_queue<pair<char,int>,vector<pair<char,int>>,Comp> q(m.begin(), m.end());
        stringstream ss;
        while(q.size() > 1){
            auto a=q.top(); q.pop();
            auto b=q.top(); q.pop();
            ss << a.first << b.first;
            --a.second; --b.second;
            if (a.second) q.push(a);
            if (b.second) q.push(b);
        }
        if (q.size()==1 && q.top().second==1 && q.top().first != ss.str().back()){
            ss << q.top().first;
            q.pop();
        }
        return q.empty() ? ss.str() : "";
    }
private:
    class Comp {
    public:
        bool operator()(const pair<char,int>& lhs, const pair<char,int>& rhs){
            return lhs.second < rhs.second;
        }
    };
};


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
    vector<int> s { 0,6,7,8,9,10 };
    int k=5;
    cout << solution.minmaxGasDist(s, k) << endl;
     */
    
    /*
    SolutionTLE s1;
    Solution s2;
    vector<int> v{ 1,0,2 };
    cout << s1.isIdealPermutation(v) << endl;
    cout << s2.isIdealPermutation(v) << endl;
    */
    
    // "aab" ==> "aba"
    // "aaab" ==> ""
    
    
    Solution s;
    while(true){
        string str;
        cin >> str;
        cout << s.reorganizeString(str) << endl;
    }
     
    
    return 0;
}
