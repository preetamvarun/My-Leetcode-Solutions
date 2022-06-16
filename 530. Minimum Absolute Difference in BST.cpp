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
    void solve(TreeNode *node, vector<int> &ds){
        if(node == NULL) return;
        ds.push_back(node->val);
        solve(node->left,ds);
        solve(node->right,ds);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>ds;
        solve(root,ds);
        sort(ds.begin(),ds.end());
        int ans = INT_MAX;
        for(int i = 0; i < ds.size()-1; i++){
            ans =  min(ans,abs(ds[i]-ds[i+1]));
        }
        return ans;
    }
};
