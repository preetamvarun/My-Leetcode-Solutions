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
    int ans = -1;
    vector<int>path;
    void solve(TreeNode *node){
        if(node == NULL) return;
        path.push_back(node->val);
        if(node->left == NULL && node->right == NULL){
            int max_num = INT_MIN, min_num = INT_MAX;
            for(int i = 0; i < path.size(); i++){
                max_num = max(max_num,path[i]);
                min_num = min(min_num,path[i]);
            }
            ans = max(ans,(max_num-min_num));
        }
        solve(node->left);
        solve(node->right);
        path.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return ans;
    }
};
