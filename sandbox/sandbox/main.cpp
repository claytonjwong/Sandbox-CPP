#include <vector>
#include <iostream>

using namespace std;
/*
int gcd(int a, int b){
    
    // gcd(a,0) = a
    // gcd(a,b) = gcd( b, a % b )
    while (b > 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

int maximumGcdAndSum(vector <int> a, vector <int> b) {
    int max_gcd = 0;
    int max_sum = 0;
    
    for (int i=0; i < a.size(); i++){
        for (int j=0; j < b.size(); j++){
            
            int curr_gcd = gcd(a[i],b[j]);
            
            if (curr_gcd > max_gcd){
                max_gcd = curr_gcd;
                max_sum = a[i] + b[i];
            }
            
            if ( curr_gcd == max_gcd && (a[i] + b[j]) > max_sum ){
                max_sum = a[i] + b[j];
            }
        }
    }
    
    return max_sum;
    
}

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

#include<set>
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> v;
        go(root,v);
        set<int> s(v.begin(),v.end());
        return is_sorted(v.begin(),v.end()) && s.size()==v.size();
    }
private:
    void go(TreeNode* root,vector<int>& inorder){
        if (!root) return;
        go(root->left,inorder);
        inorder.push_back(root->val);
        go(root->right,inorder);
    }
};

        
#include <exception>



int main() {
    
    Solution s;
    TreeNode* root=new TreeNode(10);
    root->right=new TreeNode(15);
    root->right->left=new TreeNode(6);
    cout << s.isValidBST(root) << endl;
    
    return 0;
     
}
