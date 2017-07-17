/*
 
 Write code to remove duplicates from an unsorted linked list 
 
 */

#include <iostream>
#include <set>

using namespace std;

struct node{
    int val;
    node* next;
};

class Solution{
public:
    node* remove_dups(node* list){
        
        
        // add unique values into a set
        set<int> unique;
        node* itr = list;
        while ( itr ){
            unique.insert(itr->val);
            itr = itr->next;
        }
        
        // create a new linked list populated with set values
        node* head = NULL;
        itr = NULL;
        for (auto val : unique){
            
            if (itr == NULL){
                itr = new node;
                head = itr;
            } else {
                itr->next = new node;
                itr = itr->next;
            }
            itr->val = val;
            itr->next = NULL;
        }
        
        
        return head;
    }
};

int main(int argc, const char * argv[]) {
    
    node* test = NULL;
    
    int val;
    node* itr = NULL;
    
    cout << "Input linked list values: [ (-1) to END input ]" << endl;
    while ( true ){
        
        cin >> val;
        
        if (val == -1){
            break;
        }
        
        if (itr == NULL){
            itr = new node;
            itr->val = val;
            itr->next = NULL;
            
            test = itr;
        } else {
            itr->next = new node;
            itr = itr->next;
            itr->val = val;
            itr->next = NULL;
        }
        
        
    }
    
    Solution solution;
    node* result = solution.remove_dups(test);
    
    cout << endl << "unique: " << endl;
    itr = result;
    while ( itr ){
        cout << itr->val << ", ";
        itr = itr->next;
    }
    cout << endl << endl;
    
    
    
    return 0;
}
