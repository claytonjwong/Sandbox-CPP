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



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> c(n,vector<int>(n,10001)),dp(n,vector<int>(n,0));
        for (auto& flight: flights){
            int src=flight[0],dst=flight[1],cost=flight[2];
            c[src][dst]=cost;
        }
        for (int j=1; j<n; ++j){
            dp[0][j]=c[0][j];
        }
        for (int i=1; i<n-1; ++i){
            for (int j=i+1; j<n; ++j){
                dp[i][j]=min(dp[i-1][j-1]+c[i][j],dp[i-1][j]);
            }
        }
        int mini=INT_MAX;
        for (int i=src,j=dst; i-src<=K && i-src<n; ++i){
            mini=min(mini,dp[i][j]);
        }
        
        return mini==INT_MAX ? -1 : mini;
    }
};

 
int main(int argc, const char * argv[]) {
    
    /*
    string str="12345";
    Solution s;
    auto res=s.letterCasePermutation(str);
    */
    
    /*
    
    int n=4, src=0, dst=2, K=0;
    vector<vector<int>> v{
        {0,1,100},
        {1,2,100},
        {0,2,500},
    };
    Solution s;
    s.findCheapestPrice(n,v,src,dst,K);
    */
    
    
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





