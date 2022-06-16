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
    void solve(TreeNode *node,vector<int>ds, int &ans){
        if(node == NULL) return;
        ds.push_back(node->val);
        if(node->left == NULL && node->right == NULL){
            long int power = 1, res = 0;
            for(int i = ds.size()-1; i >= 0; i--){
                res += ds[i] * power;
                power *= 10;
            }
            ans += res;
        }
        solve(node->left,ds,ans);
        solve(node->right,ds,ans);
        ds.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root,{},ans);
        return ans;
    }
};
