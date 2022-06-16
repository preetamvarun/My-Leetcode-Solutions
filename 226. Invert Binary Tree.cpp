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
    void solve(TreeNode *node){
        if(node == NULL) return;
        TreeNode *newNode = new TreeNode();
        newNode = node->left;
        node->left = node->right;
        node->right = newNode;
        solve(node->left);
        solve(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        solve(root);
        return root;
    }
};
