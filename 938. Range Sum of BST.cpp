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
    int ans = 0;
    void solve(TreeNode *node, int low, int high){
        if(node == NULL){
            return;
        }
        if(low <= node->val && node->val <= high){
            ans += node->val;
        }
        solve(node->left,low,high);
        solve(node->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        solve(root,low,high);
        return ans;
    }
};
