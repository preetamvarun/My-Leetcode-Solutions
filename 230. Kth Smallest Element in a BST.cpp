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
    void solve(TreeNode* node, vector<int> &ans){
        if(node == NULL) return;
        ans.push_back(node->val);
        solve(node->left,ans);
        solve(node->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        solve(root,ans);
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};
