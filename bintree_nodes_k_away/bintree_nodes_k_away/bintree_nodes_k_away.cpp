/*
 
 863. All Nodes Distance K in Binary Tree
 
 Q: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 A: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/144252/Straightforward-C++-(-EASY-to-understand-)-with-explanation
 
 */


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val{x},left{nullptr},right{nullptr} {}
};

using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    VI distanceK(TreeNode* root, TreeNode* T, int K, VVI G=VVI(501)) {
        gen(root,G);
        return bfs(root,G,T->val,K);
    }
private:
    void gen(TreeNode* root, VVI& G){
        if (!root) return;
        if (root->left){
            G[root->val].push_back(root->left->val);
            G[root->left->val].push_back(root->val);
            gen(root->left,G);
        }
        if (root->right){
            G[root->val].push_back(root->right->val);
            G[root->right->val].push_back(root->val);
            gen(root->right,G);
        }
    }
    VI bfs(TreeNode* root, const VVI& G, const int T, const int K){
        deque<int> q({T}); unordered_set<int> V({T});
        for (int d=0; !q.empty(); ++d){
            if (d==K)
                return {q.begin(),q.end()};
            int N=(int)q.size();
            while (N--){
                auto curr=q.front(); q.pop_front();
                for (auto nei: G[curr])
                    if (V.insert(nei).second)
                        q.push_back(nei);
            }
        }
        return {};
    }
};

int main(int argc, const char * argv[]) {
    
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(5);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(2);
    root->right->left=new TreeNode(0);
    root->right->right=new TreeNode(8);
    root->left->right->left=new TreeNode(7);
    root->left->right->right=new TreeNode(4);
    Solution s;
    auto r=s.distanceK(root,root->left,2);
    
    
    return 0;
}
