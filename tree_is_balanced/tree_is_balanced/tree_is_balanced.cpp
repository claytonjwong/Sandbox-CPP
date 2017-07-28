/*
 
 CCI 4.4  Check Balanced: Implement a function to check if a binary tree is balanced.  For the purposes of this question, a balance tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.
 
 
 */

#include <iostream>


using namespace std;

template<class T>
class Node {
public:
    Node(T val) : val{val}, left{NULL}, right{NULL} {}
    T val;
    Node<T>* left;
    Node<T>* right;
};

template<class T>
class Solution {
public:
    static bool IsBalanced(Node<T>* node){
        
        int left_depth = Solution::GetMaxDepth(node->left, 1);
        int right_depth = Solution::GetMaxDepth(node->right, 1);
        
        return abs( left_depth - right_depth ) < 2; // true if depths differ by 0 or 1
    }
    
    static int GetMaxDepth(Node<T>* node, int curr_depth){
        
        if (!node){
            return curr_depth - 1;
        }
        
        // leaf base case
        if (node && !node->left && !node->right){
            return curr_depth;
        }
        
        // non-leaf recursive case
        int left_depth=0;
        int right_depth=0;
        
        if (node && node->left){
            left_depth = Solution::GetMaxDepth(node->left, curr_depth+1);
        }
        
        if (node && node->right){
            right_depth = Solution::GetMaxDepth(node->right, curr_depth+1);
        }
        
        return max ( left_depth, right_depth );
    }
};

int main(int argc, const char * argv[]) {

    
    Node<int>* root = new Node<int>(5);
    root->left = new Node<int>(3);
    root->left->left = new Node<int>(2);
    root->left->right = new Node<int>(4);
    root->left->left->left = new Node<int>(1);
    root->right = new Node<int>(7);
    root->right->left = new Node<int>(6);
    root->right->right = new Node<int>(8);
    root->right->right->right = new Node<int>(10);
    root->right->right->right->right = new Node<int>(11);
    
    
    cout << "max depth (tree): " << Solution<int>::GetMaxDepth(root, 0) << endl;
    cout << "max depth (left): " << Solution<int>::GetMaxDepth(root->left, 1) << endl;
    cout << "max depth (right): " << Solution<int>::GetMaxDepth(root->right, 1) << endl;
    cout << "IsBalanced? true 1: " << Solution<int>::IsBalanced(root) << endl;
    

    root->right->right->right->right->right = new Node<int>(12);
    
    cout << "max depth (tree): " << Solution<int>::GetMaxDepth(root, 0) << endl;
    cout << "max depth (left): " << Solution<int>::GetMaxDepth(root->left, 1) << endl;
    cout << "max depth (right): " << Solution<int>::GetMaxDepth(root->right, 1) << endl;
    cout << "IsBalanced? false 0: " << Solution<int>::IsBalanced(root) << endl;
    
    return 0;
}





