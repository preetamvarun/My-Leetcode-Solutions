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
    bool ans = true;
    int solve(TreeNode *node){
        if(ans == false) return -1;
        if(node == NULL) return 0;
        int lh = solve(node->left);
        int rh = solve(node->right);
        if(abs(lh - rh) > 1){
            ans = false;
            return -1;
        }
        return 1 + max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int height = solve(root);
        return ans;
    }
};
