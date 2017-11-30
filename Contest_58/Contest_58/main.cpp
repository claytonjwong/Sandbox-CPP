//
//  main.cpp
//  Contest_58
//
//  Created by CLAYTON WONG on 11/11/17.
//  Copyright © 2017 Clayton Wong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

/*
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=(int)nums.size();
        vector<int> sums(n+1,0);
        for (int i=1; i<sums.size(); ++i)
            sums[i]=sums[i-1]+nums[i-1];
        for (int i=1; i<sums.size()-1; ++i)
            if (sums[i]==sums[n]-sums[i+1])
                return i;
        return -1;
    }
};
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val{x}, next{nullptr} {}
};
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k,nullptr);
        int n=0,chunk=0,leftover=0;
        ListNode* itr=root;
        while(itr){
            ++n;
            itr=itr->next;
        }
        chunk=n/k;
        leftover=n%k;
        itr=root;
        for (int i=0; itr; ++i){
            int size=leftover-- > 0 ? chunk+1 : chunk;
            ListNode *head=itr, *prev=nullptr, *curr=itr;
            for (int j=0; j<size; ++j){
                prev=curr;
                curr=curr->next;
            }
            prev->next=nullptr;
            itr=curr;
            res[i]=head;
        }
        return res;
    }
};

/*
class Solution {
public:
    class Formula {
    public:
        
    };
    string countOfAtoms(string formula) {
        string res{},s{},j{};
        map<string,int> element;
        for (int i=0; i<formula.size(); ++i){
            while (i<formula.size() && isalpha(formula[i])){
                s.push_back(formula[i]);
                ++i;
            }
            if (!s.empty()){
                element[s]=1;
                s.clear();
            }
            while (
            
            } else if (isdigit(ch)){
                j.push_back(ch);
            } else if (ch=='('){
                
            }
            
        }
        return res;
    }
};
*/

int main(int argc, const char * argv[]) {

    Solution solution;
    
    ListNode* root=new ListNode(1);
    root->next=new ListNode(2);
    root->next->next=new ListNode(3);
    root->next->next->next=new ListNode(4);
    root->next->next->next->next=new ListNode(5);
    root->next->next->next->next->next=new ListNode(6);
    root->next->next->next->next->next->next=new ListNode(7);
    root->next->next->next->next->next->next->next=new ListNode(8);
    root->next->next->next->next->next->next->next->next=new ListNode(9);
    root->next->next->next->next->next->next->next->next->next=new ListNode(10);
    
    vector<ListNode*> res=solution.splitListToParts(root, 3);
    

    
    
    return 0;
}




