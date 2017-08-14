/*
 
 
 */



#include <iostream>


#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val{val}, next{NULL} {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* result = NULL;
        ListNode* itr;
        
        vector<int> v1;
        itr = l1;
        while (itr){
            v1.push_back(itr->val);
            itr = itr->next;
        }
        
        vector<int> v2;
        itr = l2;
        while (itr){
            v2.push_back(itr->val);
            itr = itr->next;
        }
        
        int sum = 0;
        int carry = 0;
        
        while ( !v1.empty() || !v2.empty() ){
            
            sum = 0;
            
            if (!v1.empty()){
                sum += v1.back();
                v1.pop_back();
            }
            
            if (!v2.empty()){
                sum += v2.back();
                v2.pop_back();
            }
            
            sum += carry;
            
            if ( sum >= 10 ){
                carry = 1;
                sum %= 10;
            } else {
                carry = 0;
            }
            
            ListNode* curr = new ListNode(sum);
            curr->next = result;
            result = curr;
            
        }
        
        if ( carry ){
            ListNode* curr = new ListNode( carry );
            curr->next = result;
            result = curr;
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {

    
    ListNode* one = new ListNode(3);
    ListNode* curr = one;
    
    int n = 9;
    while ( n > 0){
        
        curr->next = new ListNode(9);
        curr = curr->next;
        n--;
    }
    
    
    
    ListNode* two = new ListNode(7);
    
    Solution solution;
    ListNode* result = solution.addTwoNumbers(one, two);
    
    cout << "Result: ";
    while ( result ){
        cout << result->val << ",";
        result = result->next;
    }
    cout << endl;
    
    return 0;
}
