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
    vector<vector<int>>ans;
    // int sum = 0; vector<int>ds;
    void solve(TreeNode *node,int ts,int sum, vector<int>ds){
        if(node == NULL) return;
        sum += node->val;
        ds.push_back(node->val);
        if(sum == ts && node->left == NULL && node->right == NULL) ans.push_back(ds);
        solve(node->left,ts,sum,ds);
        solve(node->right,ts,sum,ds);
        sum -= node->val;
        ds.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return ans;
        solve(root,targetSum,0,{});
        return ans;
    }
};
