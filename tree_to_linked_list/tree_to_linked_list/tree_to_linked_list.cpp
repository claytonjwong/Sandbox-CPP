/*
 
 114. Flatten Binary Tree to Linked List
 
 https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 
 Given a binary tree, flatten it to a linked list in-place.
 
 For example,
 Given
 
     1
    / \
   2   5
  / \   \
 3   4   6
 
 The flattened tree should look like:
 
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
 
 */




#include <iostream>



struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int val) : val{val}, left{NULL}, right{NULL} {}
};


class Solution{
public:
    void flatten(TreeNode* root){
        
        TreeNode* root_node = root;
        
        // make all left subtrees right subtrees
        while (root_node){
            
            if (root_node->left){
                
                TreeNode* curr_node = root_node;
                TreeNode* curr_subtree = curr_node;
                
                // save previous right subtree
                TreeNode* prev_right_subtree = curr_subtree->right;
                
                // set right subtree to left subtree
                curr_subtree->right = curr_subtree->left;
                
                // set left subtree NULL
                curr_subtree->left = NULL;
                
                // set right-most right to the previous right subtree
                while (curr_node->right){
                    curr_node = curr_node->right;
                }
                curr_node->right = prev_right_subtree;
            }
            
            root_node = root_node->right; // iterate to the right
        }
        
    }
};

int main(int argc, const char * argv[]) {

    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    Solution solution;
    solution.flatten(root);
    
    
    
    return 0;
}





