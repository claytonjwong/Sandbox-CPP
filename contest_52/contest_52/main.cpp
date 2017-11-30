//
//  main.cpp
//  contest_52
//
//  Created by CLAYTON WONG on 9/30/17.
//  Copyright © 2017 Clayton Wong. All rights reserved.
//



#include <iostream>
#include <string>
#include <set>
#include <limits>

using namespace std;

// A = "abcd"   4

//    abcdabcdabcd
// B = "cdabcdab"   8

class Solution1 {
public:
    int repeatedStringMatch(string A, string B) {
        if (A.empty() || B.empty()) { return -1; }
        set<char>setA{A.begin(),A.end()};
        set<char>setB{B.begin(),B.end()};
        if (setA==setB && A.size()==1){
            return (int)B.size();
        }
        if (setA.size()<setB.size()){
            return -1;
        }
        int res=1;
        string prev{},origA(A);
        do{
            if (A.find(B)!=string::npos){
                return res;
            }
            prev=A;
            A=A+origA;
            ++res;
        }while(prev.size()/2<B.size());
        return -1;
    }
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int longestPath=0;
        helper(root, longestPath);
        return longestPath;
    }
private:
    int helper(TreeNode* root, int& m){
        int l=root->left ? helper(root->left, m) : 0;
        int r=root->right ? helper(root->right, m) : 0;
        l=(root->left && root->left->val==root->val) ? l+1 : 0;
        r=(root->right && root->right->val==root->val) ? r+1 : 0;
        m=max(m,l+r);
        return max(l,r);
    }
};

int main(int argc, const char * argv[]) {

    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(3);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(3);
    
//    root->right=new TreeNode(5);
//    root->right->right=new TreeNode(5);
    
    
    
    Solution solution;
    cout << solution.longestUnivaluePath(root) << endl;
    
    
    return 0;
}





