/*
 
 Given two singly linked lists, determine if the two lists intersect.  Return the intersecting node.  NOte that the intersection is defined based on reference, not value.  That is, if the kth node of the first linked list is the eact same node (by reference) as the jth node of the second linked list, then they are intersecting.
 
 */

#include <iostream>

using namespace std;

struct Node{
    int val = 0;
    Node* next = NULL;
};

class Solution{
public:
    
    Node* intersect(Node*, Node*);
};

Node* Solution::intersect(Node* one, Node* two){
    
    // iterate through each linked list and keep track of their lengths
    // if the last node of each linked list is the same, then the lists intersect
    // iterate through ahead through the longer list, then move long with the
    // the shorter list to find and return the intersecting node
    
    Node* itr_one = one;
    int len_one = 0;
    while ( true ){
        if (itr_one){
            len_one++;
        
            if (itr_one->next){
                itr_one = itr_one->next;
            } else {
                break; // exit loop when itr_one points to the last node
            }
        }
    }

    Node* itr_two = two;
    int len_two = 0;
    while ( true ){
        if (itr_two){
            len_two++;
            
            if (itr_two->next){
                itr_two=itr_two->next;
            } else {
                break; // exit loop when itr_two points to the last node
            }
        }
    }

    // if the last nodes of each list are NOT the same node, then these lists do NOT interset
    if (itr_one != itr_two){
        return NULL;
    }
    
    // find the longer and shorter lists
    Node* itr_short;
    Node* itr_long;
    if (len_one < len_two){
        itr_short = one;
        itr_long = two;
    } else {
        itr_short = two;
        itr_long = one;
    }
    
    // iterate forward by the length difference between the longer and shorter list
    int diff = abs ( len_one - len_two );
    while ( diff > 0 ){
        itr_long = itr_long->next;
        diff--;
    }
    
    // iterate fowards together to find the first intersecting node
    while (itr_long && itr_short){
        if (itr_long == itr_short){
            return itr_long;
        }
        
        itr_long = itr_long->next;
        itr_short = itr_short->next;
    }
    
    
    return NULL;
}

int main(int argc, const char * argv[]) {
    
    Node* one = new Node;
    one->val = 1;
    one->next = new Node;
    one->next->val = 2;
    one->next->next = new Node;
    one->next->next->val = 3;
    one->next->next->next = NULL;
    
    Node* two = new Node;
    two->val = 0;
    two->next = new Node;
    two->next->val = 1;
    two->next->next = NULL;
    
    Solution solution;
    Node* result = solution.intersect(one,two);
    
    if (result == NULL){
        cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
    }
    
    return 0;
}
