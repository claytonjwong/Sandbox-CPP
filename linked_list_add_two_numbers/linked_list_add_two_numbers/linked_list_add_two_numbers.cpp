/*
 
 2. Add Two Numbers
 
 https://leetcode.com/problems/add-two-numbers/description/
 
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 
 */

#include <iostream>

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
        ListNode* curr = NULL;
        
        if (!l1){
            result = l2;
        }
        if (!l2){
            result = l1;
        }
        
        int carry = 0;
        while(l1 || l2){
            
            int value1 = 0;
            int value2 = 0;
            
            if (l1){
                value1 = l1->val;
                l1 = l1->next;
            }
            if (l2){
                value2 = l2->val;
                l2 = l2->next;
            }
            
            int sum = value1+value2+carry;
            
            if (sum >= 10){
                carry = 1;
                sum %= 10;
            } else {
                carry = 0;
            }
            
            if (!result){
                result = new ListNode(sum);
                curr = result;
            } else {
                curr->next = new ListNode(sum);
                curr = curr->next;
            }
        }
        
        if (carry){
            curr->next = new ListNode(carry);
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {

    ListNode* list1 = new ListNode(2);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(3);
    
    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(4);
    
    Solution solution;
    ListNode* result = solution.addTwoNumbers(list1, list2);
    
    string output = "";
    while (result){
        output += to_string(result->val);
        
        if (result->next){
            output += "->";
        }
        result = result->next;
    }
    
    cout << output << endl;
    
    return 0;
}




