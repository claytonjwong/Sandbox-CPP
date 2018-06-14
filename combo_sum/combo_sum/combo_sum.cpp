/*
 
 39. Combination Sum
 
 Q: https://leetcode.com/problems/combination-sum/description/
 A:
 
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

using VI=vector<int>;
using VVI=vector<VI>;
using SVI=set<VI>;
class Solution {
public:
    VVI combinationSum(VI& A, int T, VI path={}, SVI ans={}) {
        return dfs(A,T,path,ans);
    }
private:
    VVI dfs(const VI& A, const int T, VI& path, SVI& ans, int sum=0){
        if (sum==T){
            VI x(path);
            sort(x.begin(),x.end());
            ans.emplace(std::move(x));
            return VVI{};
        }
        for (int i=0,N=(int)A.size(); i<N; ++i){
            path.push_back(A[i]);
            if (sum+A[i]<=T)
                dfs(A,T,path,ans,sum+A[i]);
            path.pop_back();
        }
        return path.empty() ? VVI{ans.begin(),ans.end()} : VVI{};
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    VI A{2,3,5}; int T=8;
    auto r=s.combinationSum(A, T);


    return 0;
}


