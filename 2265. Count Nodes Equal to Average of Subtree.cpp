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
    int nc = 0, sum = 0;
    pair<int,int> solve(TreeNode *node){
        if(node == NULL) return {0,0};
        pair<int,int> left_sum = solve(node->left);
        pair<int,int> right_sum = solve(node->right);
        if((left_sum.first + right_sum.first + node->val)/ (left_sum.second + right_sum.second + 1) == node->val) nc++;
        return {left_sum.first + right_sum.first + node->val, left_sum.second + right_sum.second + 1};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return nc;
    }
};
