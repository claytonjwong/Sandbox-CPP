/*
 
 https://leetcode.com/contest/weekly-contest-75/
 
 Rank       Name            Score    Finish Time     Q1 (3)     Q2 (5)    Q3 (7)    Q4 (7)
 759 / 2830 claytonjwong    8        0:30:18         0:03:20    0:30:18
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

/*
 //AC
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A==B) return true;
        for (int i=0; i<A.size(); ++i){
            char c=A.back(); A.pop_back();
            A=c+A;
            if (A==B) return true;
        }
        return false;
    }
};
 */
/*
 //AC
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        unordered_set<int> visited;
        vector<int> path;
        go(res,graph,0,(int)graph.size()-1,visited,path);
        return res;
    }
private:
    void go(vector<vector<int>>& r, vector<vector<int>>& g, int i, int t,
            unordered_set<int>& v, vector<int>& p){
        v.insert(i);
        p.push_back(i);
        
        if (i==t){
            r.push_back(p);
        } else {
            for (auto nei: g[i])
                if (!v.count(nei))
                    go(r,g,nei,t,v,p);
        }
        
        v.erase(i);
        p.pop_back();
    }
};
*/

/*
class Solution {
public:
    int bestRotation(vector<int>& A) {
        return 0;
    }
};
 */

// Wrong Answer
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double res=0.0;
        int row=0;
        while (poured>row+1){
            ++row;
            poured-=row;
        }
        if (query_row<row) return 1.0;
        if (query_row>row) return 0.0;
        vector<vector<double>> ratio(query_row+1,vector<double>(query_row+1));
        ratio[0][0]=1.0;
        int size=2;
        for (int i=1; i<=query_row; ++i){
            for (int j=0; j<size; ++j){
                if (j>0){
                    ratio[i][j]=(ratio[i-1][j-1]+ratio[i-1][j])/2.0;
                } else {
                    ratio[i][j]=(ratio[i-1][j])/2.0;
                }
            }
            ++size;
        }
        return poured*ratio[query_row][query_glass];
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    /*
    string A="abcde",B="abced";
    cout << s.rotateString(A, B) << endl;
    */
    
    /*
    vector<vector<int>> graph {
        {1,2},
        {3},
        {3},
        {},
    };
    auto res=s.allPathsSourceTarget(graph);
    */
    
    //double champagneTower(int poured, int query_row, int query_glass) {
    
    cout << s.champagneTower(6, 2, 1) << endl;
    
    
    return 0;
}




