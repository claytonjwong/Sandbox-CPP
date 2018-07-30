/*
 
 Clone a linked list comprised of nodes related to other nodes in the linked list.
 A node is related to another node in the linked list when its value
 points towards that node.  Every node is guaranteed to be related to another node in the list.
 A node may be related to itself.
 
 For example: the following linked list contains 3 nodes: 1,2,3
 
 ---------------
 |     ---     |
 |     | |     |
 V     | V     V
 1 ---> 2 ---> 3 ---> NULL
 
 Each "next" node in the linked list is denoted above as --->
 
 Each node's relationships are as follows:
 
 node 1 is related to node 3
 node 2 is related to node 2 ( itself )
 node 3 is related to node 1
 
 The cloned linked list should contain the same relative values
 in separate and distinct memory.
 
 ---------------
 |     ---     |
 |     | |     |
 V     | V     V
 1 ---> 2 ---> 3 ---> NULL
 
 */

#pragma once

struct ListNode {
    ListNode *val,*next;
    ListNode(ListNode* x) : val{x},next{nullptr} {}
};

//
// 1) create out "clone" with val equal to in's val
// 2) update in val to to point towards its corresponding out "clone"
// 3) iterate through out and update the out value to the node two-hops away
//
// Note: at step #3 above, out's val points to in's previous val
// and in's previous value points to its corresponding out "clone",
// therefore, update out's val to the node two-hops away
//
// ( i.e. out ---> previous in ---> out "clone" )
//
class Solution {
public:
    ListNode* clone(ListNode* head) {
        if (head==nullptr)
            return nullptr;
        ListNode* sentinel=new ListNode(nullptr);
        for (auto in=head,out=sentinel; in; in=in->next,out=out->next) // step #1 and step #2
            in->val=out->next=new ListNode(in->val);
        for (auto out=sentinel->next; out; out=out->next) // step #3
            out->val=(out->val)->val;
        return sentinel->next;
    }
};

