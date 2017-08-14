/*
 
 206. Reverse Linked List
 
 https://leetcode.com/problems/reverse-linked-list/description/
 
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
    ListNode* reverseList(ListNode* head) {
        
        if (!head){ return NULL; }
        if (!head->next) { return head; }
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while (curr){
            
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            curr = prev->next;
        }
        
        return head;
    }
    
    void PrintList(ListNode* list){
        while (list){
            cout << list->val << ",";
            list = list->next;
        }
        cout << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    
    cout << "Before: ";
    solution.PrintList(list);
    
    list = solution.reverseList(list);
    
    cout << "After: ";
    solution.PrintList(list);
    
    return 0;
}



