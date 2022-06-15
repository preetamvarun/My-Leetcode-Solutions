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
    vector<string>ans;
    void solve(TreeNode *node, vector<int> ds){
        if(node->left == NULL && node->right == NULL){
            ds.push_back(node->val);
            string res = "";
            for(int i = 0; i < ds.size(); i++){
                res += to_string(ds[i]);
                if(i != ds.size() - 1) res += "->";
            }
            ans.push_back(res);
            return;
        }
        ds.push_back(node->val);
        if(node->left != NULL) solve(node->left,ds);
        if(node->right != NULL) solve(node->right,ds);
        ds.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>ds;
        solve(root,ds);
        return ans;
    }
};
