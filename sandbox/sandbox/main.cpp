#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;
/*
int gcd(int a, int b){
    
    // gcd(a,0) = a
    // gcd(a,b) = gcd( b, a % b )
    while (b > 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

int maximumGcdAndSum(vector <int> a, vector <int> b) {
    int max_gcd = 0;
    int max_sum = 0;
    
    for (int i=0; i < a.size(); i++){
        for (int j=0; j < b.size(); j++){
            
            int curr_gcd = gcd(a[i],b[j]);
            
            if (curr_gcd > max_gcd){
                max_gcd = curr_gcd;
                max_sum = a[i] + b[i];
            }
            
            if ( curr_gcd == max_gcd && (a[i] + b[j]) > max_sum ){
                max_sum = a[i] + b[j];
            }
        }
    }
    
    return max_sum;
    
}

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

#include<set>
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> v;
        go(root,v);
        set<int> s(v.begin(),v.end());
        return is_sorted(v.begin(),v.end()) && s.size()==v.size();
    }
private:
    void go(TreeNode* root,vector<int>& inorder){
        if (!root) return;
        go(root->left,inorder);
        inorder.push_back(root->val);
        go(root->right,inorder);
    }
};
*/

/*
#include <exception>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val{val}, next{nullptr} {}
};

ListNode* rev(ListNode* head){
    if (!head || !head->next) return head;
    ListNode *prev=head, *curr=prev->next;
    while (curr){
        prev->next=curr->next;
        curr->next=head;
        head=curr;
        curr=prev->next;
    }
    return head;
}
*/

void ProcessStr( string && str ) // takes rvalue reference
{
    cout << "rval" << endl;
}
void ProcessStr( string & str ) // takes lvalue reference
{
    cout << "lval" << endl;
}
void Foo()
{
    ProcessStr( "ABC" );
    ProcessStr( string( "123" ));
    string myStr("XYZ");
    ProcessStr( myStr );
}

#include <map>
#include <set>
#include <memory>

struct X {
    int val;
};

template<typename T>
void sink(unique_ptr<T> releaseMe) {}


//template<typename T1> // does NOT compile
//template<typename T2>
template<typename T1, typename T2>
T1 add(const T1& a, const T2& b){
    return a+b;
}

template <typename T>
class Stack
{
public:
    template < typename T2 >
    Stack<T> & operator = (const Stack<T2> & other );
};

template <typename T>
template <typename T2>
//template <typename T, typename T2> // does NOT compile
Stack<T> & Stack<T>::operator = (const Stack<T2> & other ) {
    return *this;
}

void g(){
    
}

void f(){
    g();
}

#include <unordered_set>



int main() {
    
    
    
    /*
     
     i+j*N
     
     i j
     0,1
     1,0
     
     0+1*N=N
     1+0*N=1
     
     */
    
    /*
    Solution s;
    TreeNode* root=new TreeNode(10);
    root->right=new TreeNode(15);
    root->right->left=new TreeNode(6);
    cout << s.isValidBST(root) << endl;
    */
    
    /*
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    auto r=rev(head);
     */
    
    /*
    vector<int> v;
    int c=(int)v.capacity(); for (int i=0; i<10000007; ++i){
        v.push_back(i);
        if (c < v.capacity()){
            cout << c << endl;
            c=(int)v.capacity();
        }
    }
    cout << c << endl << endl;
     */
    
    /*
    struct cmp{
        bool operator()(const pair<string,int>& lhs, pair<string,int>& rhs){
            return lhs.second < rhs.second;
        }
    };
    
    unordered_map<string,int> M;
    
    while (true) {
        string name;
        cout << "name: "; cin >> name;
        if (name=="exit")
            break;
        ++M[name];
    }
    priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> q(M.begin(),M.end());
    
    while (!q.empty()){
        auto curr=q.top(); q.pop();
        cout << curr.first << "   " << curr.second << endl;
    }
    */
    
    
    
    return 0;
     
}
