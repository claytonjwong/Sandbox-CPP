/*
 
 96. Unique Binary Search Trees
 
 https://leetcode.com/problems/unique-binary-search-trees/description/
 
 Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 
 For example,
 Given n = 3, there are a total of 5 unique BST's.
 
 1         3     3      2      1
  \       /     /      / \      \
   3     2     1      1   3      2
  /     /       \                 \
 2     1         2                 3
 
 */

/*
 
 psuedo:
 
 let dp[k] represent the amount of unique ways to create a tree with k nodes from [1:k] inclusive
 
 for each k from [2:n]
     for each i as root from [2:k]
        root.left will contain nodes [1:i-1], the # of nodes is (i-1)-(1)+1 == i-1
        root.right will contain nodes [i+1:k], the # of nodes is (k)-(i+1)+1 == k-i
        lookup the precomputed values for dp[i-1] and dp[k-i], multiply them, and add to sum
    store sum in dp[k]
 ret dp[n]
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=dp[1]=1; // there is one way to make a tree with 0 or 1 nodes
        for (int k=2; k<=n; ++k){
            int sum=0;
            for (int i=1; i<=k; ++i) sum+=dp[i-1]*dp[k-i];
            dp[k]=sum;
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    while (true){
        int n;
        cout << "n: "; cin >> n;
        cout << s.numTrees(n) << endl;
    }
    return 0;
}



