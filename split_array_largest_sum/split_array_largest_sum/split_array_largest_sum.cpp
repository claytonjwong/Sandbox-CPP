/*
 
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& A, int K, int ans=INT_MAX) {
        vector<int> S(A.size()+1,0);
        for (int i=1,N=(int)S.size(); i<N; ++i) S[i]=S[i-1]+A[i-1];
        
        go(ans,S,K);
        return ans;
    }
private:
    int go(int& ans, const vector<int>& S, int K, int beg=0, int sum=0, int maxi=INT_MIN){
        if (K==0) return 0;
        for (int i=1,N=(int)S.size(); beg+i<=N-K; ++i){
            sum=S[beg+i]-S[beg];
            maxi=max(sum,go(ans,S,K-1,beg+i));
        }
        ans=min(ans,maxi);
        return maxi;
    }
};

int main(int argc, const char * argv[]) {
    
    //vector<int> A{10,5,13,4,8,4,5,11,14,9,16,10,20,8}; int K=8;
    vector<int> A{7,2,5,10,8}; int K=2;
    Solution s;
    auto r=s.splitArray(A,K);
    
    return 0;
}


