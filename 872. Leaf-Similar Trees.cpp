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
    vector<int>v,v1;
    void solve1(TreeNode *node){
        if(node == NULL) return;
        else if(node->left == NULL && node->right == NULL) v1.push_back(node->val);
        solve1(node->left);
        solve1(node->right);
    }
    void solve(TreeNode *node){
        if(node == NULL) return;
        else if(node->left == NULL && node->right == NULL) v.push_back(node->val);
        solve(node->left);
        solve(node->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        solve(root1);
        solve1(root2);
        return v == v1;
    }
};
