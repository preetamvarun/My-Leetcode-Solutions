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
    int sum = 0;
    void solve(TreeNode *node, vector<int>ds){
        if(node == NULL) return;
        ds.push_back(node->val);
        if(node->left == NULL && node->right == NULL){
            int power = 0, res = 0;
            for(int i = ds.size()-1; i >= 0; i--){
                res += (ds[i] * pow(2,power));
                power++;
            }
            sum += res;
        }
        solve(node->left,ds);
        solve(node->right,ds);
        ds.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        solve(root,{});
        return sum;
    }
};
