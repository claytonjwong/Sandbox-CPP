/*
 
 663. Equal Tree Partition
 
 https://leetcode.com/problems/equal-tree-partition/description/
 
 Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.
 
 Example 1:
 Input:
 5
 / \
 10 10
 /  \
 2   3
 
 Output: True
 Explanation:
 5
 /
 10
 
 Sum: 15
 
 10
 /  \
 2    3
 
 Sum: 15
 Example 2:
 Input:
 1
 / \
 2  10
 /  \
 2   20
 
 Output: False
 Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
 Note:
 The range of tree node value is in the range of [-100000, 100000].
 1 <= n <= 10000
 
 */

#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val{x}, left{NULL}, right{NULL} {}
};

class Solution{
public:
    bool checkEqualTree(TreeNode* root){
        set<int> s{};
        int sum=sums(root, s, true);
        return !s.empty() && sum%2==0 && s.find(sum/2)!=s.end();
    }
private:
    int sums(TreeNode* root, set<int>& s, bool isRoot){
        if (!root) { return 0; }
        int sum=root->val+sums(root->left,s,false)+sums(root->right,s,false);
        if (!isRoot) { s.insert(sum); }
        return sum;
    }
};

class Solution2{
public:
    int tSum(TreeNode* r, unordered_multiset<long long>& s) {
        return r == nullptr ? 0 : *s.insert(r->val + tSum(r->left, s) + tSum(r->right, s));
    }
    bool checkEqualTree(TreeNode* root) {
        unordered_multiset<long long> sums;
        auto sum = tSum(root, sums);
        return sum % 2 == 0 && sums.size() > 1 && sums.find(sum / 2) != sums.end();
    }
};

class Solution3{
public:
    bool checkEqualTree(TreeNode* r) {
        unordered_set<int> s;
        int p = sum(r, s, true);
        return !(p % 2) && s.count(p / 2) > 0;
    }
    
    int sum(TreeNode *r, unordered_set<int> &s, bool isroot) {
        if (!r) return 0;
        auto v = r->val + sum(r->left, s, false) + sum(r->right, s, false);
        int retval=0;
        if (isroot) {
            retval=v;
        } else {
            retval=*s.insert(v).first;
        }
        return retval;
    }
};

int main(int argc, const char * argv[]) {
    
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(1);

    
    Solution solution;
    cout << solution.checkEqualTree(root) << endl;
    
    
    
    return 0;
}





