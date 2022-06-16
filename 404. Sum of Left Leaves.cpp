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
    void solve(TreeNode *node,TreeNode *temp){
        if(node == NULL) return;
        if(node->left == NULL && node->right == NULL){
            if(temp != NULL && temp->left == node){
                ans += node->val;
            }
        }
        temp = node;
        solve(node->left,temp);
        solve(node->right,temp);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root,NULL);
        return ans;
    }
};
