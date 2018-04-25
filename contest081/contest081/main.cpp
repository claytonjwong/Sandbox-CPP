/*
 
 https://leetcode.com/contest/weekly-contest-81/ranking
 
 Rank           Name                Score       Finish Time      Q1 (4)    Q2 (5)    Q3 (6)    Q4 (7)
 897 / 2797     claytonjwong        9           1:13:16          0:16:45   1:08:16  1
 
 Q1: https://leetcode.com/problems/shortest-distance-to-a-character/description/
 A1: https://leetcode.com/problems/shortest-distance-to-a-character/discuss/125821/Concise-and-Verbose-C++
 
 Q2: https://leetcode.com/problems/card-flipping-game/description/
 A2: https://leetcode.com/problems/card-flipping-game/discuss/125805/C%2B%2B-Set...-Simple-and-Concise-with-Explanation/126688?page=1
 
 Q3: https://leetcode.com/problems/short-encoding-of-words/description/
 A3: https://leetcode.com/problems/short-encoding-of-words/discuss/125848/Concise-C++-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int N=(int)S.size();
        vector<int> d(N);
        for (int i=0,j=(int)S.find_first_of(C); i<N; ++i){
            if (S[i]==C)
                j=i;
            d[i]=abs(i-j);
        }
        for (int i=N-1,j=(int)S.find_last_of(C); i>=0; --i){
            if (S[i]==C)
                j=i;
            d[i]=min(d[i],abs(i-j));
        }
        return d;
    }
};
*/

/*
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int N=(int)S.size();
        vector<int> d(N,INT_MAX);
        int k=(int)S.find_first_of(C),l=(int)S.find_last_of(C);
        for (int i=0,j=N-1; i<N; ++i,--j){
            if (S[i]==C) k=i;
            if (S[j]==C) l=j;
            d[i]=min(d[i],abs(i-k));
            d[j]=min(d[j],abs(j-l));
        }
        return d;
    }
};
*/

/*
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int> c,x;
        int N=(int)fronts.size();
        for (int i=0; i<N; ++i)
            if (fronts[i]==backs[i])
                x.insert(fronts[i]);
        for (int i=0; i<N; ++i){
            if (x.find(fronts[i])==x.end())
                c.insert(fronts[i]);
            if (x.find(backs[i])==x.end())
                c.insert(backs[i]);
        }
        return *min_element(c.begin(), c.end());
    }
};
*/

/*
class Solution {
public:
    int flipgame(vector<int>& f, vector<int>& b) {
        unordered_set<int> c(f.begin(),f.end()); c.insert(b.begin(),b.end());
        for (int i=0; i<(int)f.size(); ++i) if (f[i]==b[i]) c.erase(f[i]);
        return c.empty() ? 0 : *min_element(c.begin(), c.end());
    }
};
 */

//int mini=INT_MAX; for (auto x: c) mini=min(mini,x);
//return mini==INT_MAX ? 0 : mini;

/*
class Solution {
public:
    int flipgame(vector<int>& f, vector<int>& b) {
        int ans=INT_MAX;
        unordered_set<int> x;
        for (int i=0; i<f.size(); ++i)
            if (f[i]==b[i]) x.insert(f[i]);
        for (int i=0; i<f.size(); ++i){
            if (x.find(f[i])==x.end()) ans=min(ans,f[i]);
            if (x.find(b[i])==x.end()) ans=min(ans,b[i]);
        }
        return ans==INT_MAX ? 0 : ans;
    }
};
 */

/*
class Solution {
public:
    int minimumLengthEncoding(vector<string>& w) {
        for (auto& x: w) reverse(x.begin(),x.end());
        sort(w.begin(),w.end());
        int ans=0,last=(int)w.back().size();
        for (int i=1; i<w.size(); ++i)
            if (w[i-1]!=w[i].substr(0,w[i-1].size()))
                ans+=w[i-1].size()+1;
        return ans+last+1;
    }
};
*/

/*
class Solution {
public:
    int minimumLengthEncoding(vector<string>& w) {
        unordered_set<string> all(w.begin(),w.end()),can(w.begin(),w.end());
        for (auto x: all)
            for (int i=1; i<x.size(); ++i)
                can.erase(x.substr(i));
        int minlen=0;
        for (auto x: can)
            minlen+=(int)x.size()+1;
        return minlen;
    }
};
*/


/*
 32 / 47 test cases passed.
 Status: Wrong Answer
 Submitted: 3 minutes ago
 Input:
 [45,42,2,18,23,1170,12,41,40,9,47,24,33,28,10,32,29,17,46,11,759,37,6,26,21,49,31,14,19,8,13,7,27,22,3,36,34,38,39,30,43,15,4,16,35,25,20,44,5,48]
 Output:
 587
 Expected:
 777
 */
/*
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        set<int> S(A.begin(),A.end());
        unordered_map<int,int> M;
        int cnt=0;
        for (auto x: S){
            ++cnt;
            cnt+=go(x,S,set<int>(S.begin(),S.upper_bound(floor(sqrt(x)))),M);
        }
        return cnt;
    }
private:
    int go(int x, const set<int>& S, const set<int>& C, unordered_map<int,int>& M){
        if (M.find(x)!=M.end()) return M[x];
        int cnt=0;
        for (int i: C){
            if (x%i) continue;
            int j=x/i;
            if (S.find(j)==S.end()) continue;
            if (i==j){
                cnt+=go(i,S,C,M);
            } else {
                cnt+=2+(2*(go(i,S,C,M)+go(j,S,C,M)));
            }
        }
        return M[x]=cnt;
    }
};
*/

 
int main(int argc, const char * argv[]) {
    
    /*
    string S="loveleetcode";
    char C='e';
    Solution s;
    auto r=s.shortestToChar(S, C);
    */
    
    /*
    Solution s;
    vector<int> f={1,1};
    vector<int> b={1,1};
    auto r=s.flipgame(f, b);
    */
    
    /*
    Solution s;
    vector<string> w={ "time", "bell", "time", "me" };
    auto r=s.minimumLengthEncoding(w);
    */
    
    
    Solution s;
    //vector<int> A={18,3,6,2};
    //vector<int> A={81,9,3};
    vector<int> A={45,42,2,18,23,1170,12,41,40,9,47,24,33,28,10,32,29,17,46,11,759,37,6,26,21,49,31,14,19,8,13,7,27,22,3,36,34,38,39,30,43,15,4,16,35,25,20,44,5,48};
    cout << s.numFactoredBinaryTrees(A) << endl;
    
    
    return 0;
}



