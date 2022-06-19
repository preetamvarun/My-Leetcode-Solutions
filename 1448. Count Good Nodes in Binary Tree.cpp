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
    int gn = 0, maxValue = INT_MIN;
    vector<int>path;
    void solve(TreeNode *node){
        if(node == NULL) return;
        path.push_back(node->val);
        if(node->val >= maxValue){
            maxValue = node->val;
            gn++;
        }
        solve(node->left);
        solve(node->right);
        path.pop_back();
        maxValue = INT_MIN;
        for(int i = 0; i < path.size(); i++) maxValue = max(maxValue,path[i]);
    }
    int goodNodes(TreeNode* root) {
        solve(root);
        return gn;
    }
};
