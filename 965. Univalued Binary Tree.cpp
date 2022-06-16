/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *node,set<int>&s){
        if(node == NULL) return;
        s.insert(node->val);
        solve(node->left,s);
        solve(node->right,s);
    }
    bool isUnivalTree(TreeNode* root) {
        set<int>s;
        solve(root,s);
        return s.size() == 1;
    }
};
