/*
 
 Trees: Is This a Binary Search Tree?
 
 https://www.hackerrank.com/challenges/ctci-is-binary-search-tree?h_r=next-challenge&h_v=zen
 
 Check out the resources on the page's right side to learn more about binary search trees. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.
 For the purposes of this challenge, we define a binary search tree to be a binary tree with the following ordering properties:
 
 The  value of every node in a node's left subtree is less than the data value of that node.
 The  value of every node in a node's right subtree is greater than the data value of that node.
 Given the root node of a binary tree, can you determine if it's also a binary search tree?
 
 Complete the function in your editor below, which has  parameter: a pointer to the root of a binary tree. It must return a boolean denoting whether or not the binary tree is a binary search tree. You may have to write one or more helper functions to complete this challenge.
 
 Note: We do not consider a binary tree to be a binary search tree if it contains duplicate values.
 
 Input Format
 
 You are not responsible for reading any input from stdin. Hidden code stubs will assemble a binary tree and pass its root node to your function as an argument.
 
 Constraints
 
 Output Format
 
 You are not responsible for printing any output to stdout. Your function must return true if the tree is a binary search tree; otherwise, it must return false. Hidden code stubs will print this result as a Yes or No answer on a new line.
 
 Sample Input
 
 tree
 
 Sample Output
 
 Yes
 Explanation
 
 The tree in the diagram satisfies the ordering property for a Binary Search Tree, so we print Yes.
 
 */


/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.
 
 The Node struct is defined as follows:
 struct Node {
 int data;
 Node* left;
 Node* right;
 }
 */

struct Node {
    int data;
    Node* left;
    Node* right;
};


#include <iostream>
#include <deque>



using namespace std;

//bool checkBST(Node* root) {
//    if (!root){
//        return false;
//    }
//    
//    // pre-order traversal
//    deque<Node*> q;
//    Node* prev = NULL;
//    Node* curr = NULL;
//    q.push_back(root);
//    while (!q.empty()){
//        prev = curr;
//        curr = q.front();
//        q.pop_front();
//        
//        if (prev && prev->data >= curr->data){
//            return false;
//        }
//        
//        if (curr->left){
//            q.push_back(curr->left);
//        }
//        if (curr->right){
//            q.push_back(curr->right);
//        }
//    }
//    
//    return true;
//}




int main(int argc, const char * argv[]) {
    
    
    
    
    
    return 0;
}





