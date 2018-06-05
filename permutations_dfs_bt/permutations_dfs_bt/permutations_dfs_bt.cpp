/*
 
 46. Permutations
 
 Q: https://leetcode.com/problems/permutations/description/
 A: https://leetcode.com/problems/permutations/discuss/136424/Straightforward-C++-DFS-with-backtracking
 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    unordered_set<int> V;
    vector<int> path;
    vector<vector<int>> ans;
    void go(const vector<int>& A){
        int M=(int)path.size(),N=(int)A.size();
        if (M==N){
            ans.push_back(path);
            return;
        }
        for (int i=0; i<N; ++i){
            if (V.insert(i).second){
                path.push_back(A[i]);
                go(A);
                V.erase(i);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& A) {
        ans.clear();
        go(A);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<int> A{1,1,2};
    auto r=s.permute(A);
    
    
    return 0;
}


