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
    bool ans = false;
    
    void solve(TreeNode *node,int sum,int targetSum){
        if(ans) return;
        if(node->left == NULL && node->right == NULL){
            if(sum == targetSum){
                ans = true;
            }
            sum -= node->val;
            return;
        }
        if(node->left != NULL) solve(node->left,sum + node->left->val,targetSum);
        if(node->right != NULL) solve(node->right,sum + node->right->val,targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        solve(root,root->val,targetSum);
        return ans;
    }
};
