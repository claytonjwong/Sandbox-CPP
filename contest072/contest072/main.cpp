/*
 
 https://leetcode.com/contest/weekly-contest-72/ranking/39/
 
 Rank           Name            Score   Finish Time     Q1 (4)          Q2 (6)    Q3 (8)    Q4 (8)
 968 / 2382     claytonjwong    4       0:46:26         0:36:26  *2
 
 */

using namespace std;

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>

/*
 // TLE
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        set<string> v;
        queue<string> q({S});
        while (!q.empty()){
            auto curr=q.front(); q.pop();
            v.insert(curr);
            for (int i=0; i<curr.size(); ++i){
                if (isalpha(curr[i])){
                    auto next=curr;
                    next[i]=isupper(next[i]) ? tolower(next[i]) : toupper(next[i]);
                    if (!v.count(next)){
                        q.push(next);
                    }
                }
            }
        }
        return vector<string>(v.begin(),v.end());
    }
};
*/

/*
 // AC
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        unordered_set<string> v;
        int sz=min(12,(int)S.size());
        for (int i=0; i<=(2<<sz)-1; ++i){
            string next(S);
            for (int j=sz-1; j>=0; --j)
                if (i&(1<<j) && isalpha(S[j]))
                    next[j]=isupper(next[j]) ? tolower(next[j]) : toupper(next[j]);
            v.insert(next);
        }
        return vector<string>(v.begin(),v.end());
    }
};
 */

/*
 // AC
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        unordered_set<string> res;
        go(res,S,0);
        return vector<string>(res.begin(),res.end());
    }
private:
    void go(unordered_set<string>& res, string s, int i){
        if (i==s.size()){
            res.insert(s);
            return;
        }
        s[i]=toupper(s[i]);
        go(res,s,i+1);
        s[i]=tolower(s[i]);
        go(res,s,i+1);
    }
};
*/
/*
 // maybe correct solution, but to the wrong problem,
 // i assumed this was the same as the "train station"
 // problem in the DP book
 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> c(n,vector<int>(n,10001)),dp(n,vector<int>(n,0));
        for (auto& flight: flights){
            int src=flight[0],dst=flight[1],cost=flight[2];
            c[src][dst]=cost;
        }
        for (int j=0; j<n; ++j){
            dp[0][j]=c[0][j];
            dp[j][j]=0;
        }
        for (int i=1; i<n-1; ++i){
            for (int j=i+1; j<n; ++j){
                dp[i][j]=min(dp[i-1][j-1]+c[i][j],dp[i-1][j]);
            }
        }
        int mini=10001;
        for (int i=src,j=dst; i-src<=K && i<n; ++i){
            mini=min(mini,dp[i][j]);
        }
        return mini==10001 ? -1 : mini;
    }
};
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int beg, int end, int K) {
        unordered_map<int,vector<pair<int,int>>> umap;
        for (auto& flight: flights){
            int src=flight[0],dst=flight[1],cost=flight[2];
            umap[src].push_back({dst,cost});
        }
        vector<int> curr(n,INT_MAX);
        curr[beg]=0;
        while (K-- >= 0){
            vector<int> next(curr);
            for (int src=0; src<n; ++src){
                if (curr[src]==INT_MAX) continue;
                for (auto& flight: umap[src]){
                    int dst=flight.first,cost=flight.second;
                    next[dst]=min(next[dst],curr[src]+cost);
                }
            }
            curr.swap(next);
        }
        return curr[end]==INT_MAX ? -1 : curr[end];
    }
};

#define mp make_pair
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define FORA(e,c) for(auto &e:c)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
typedef const int CI;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef vector<int> VINT;
typedef vector<ld> VLD;
typedef vector<ll> VLL;
typedef vector<vector<int>> VVINT;
typedef set<int> SI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<ll, ll> PLL;
typedef pair<ld, ld> PLD;
typedef pair<ld, ld> ptp;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PIII> VPIII;
typedef vector<PLD> VPLD;
typedef set<PII> SII;
const int oo=0x3F3F3F3F;
const ll ooLL=0x3F3F3F3F3F3F3F3FLL;
#define pb push_back
#define X first
#define Y second
/*
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int K) {
        vector<VPII> g(n);
        FORA(x, fl) {
            g[x[0]].push_back({x[1], x[2]});
        }
        VINT d(n, -1);
        d[src] = 0;
        REP(it, K+1) {
            VINT f=d;
            REP(i, n) {
                if (d[i] == -1) continue;
                FORA(x, g[i]) {
                    int t=x.X, c=d[i]+x.Y;
                    if (f[t] == -1 || f[t] > c) f[t] = c;
                }
            }
            d.swap(f);
        }
        return d[dst];
    }
};
*/
int main(int argc, const char * argv[]) {
    
    /*
    string str="ab";
    Solution s;
    auto res=s.letterCasePermutation(str);
    */
    
    
    int n=4, src=0, dst=2, K=1;
    vector<vector<int>> v{
        {0,1,100},
        {1,2,100},
        {0,2,500},
    };
    
    Solution s;
    cout << s.findCheapestPrice(n,v,src,dst,K) << endl;
    
    
    
    /*
     10
     [[3,4,4],[2,5,6],[4,7,10],[9,6,5],[7,4,4],[6,2,10],[6,8,6],
     [7,9,4],[1,5,4],[1,0,4],[9,7,3],[7,0,5],[6,5,8],[1,7,6],
     [4,0,9],[5,9,1],[8,7,3],[1,2,6],[4,1,5],[5,2,4],[1,9,1],[7,8,10],[0,4,2],[7,2,8]]
     6
     0
     7
     */
    
    return 0;
}





