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
    int ans = 0; map<int,int>mp;
    void solve(TreeNode *node){
        if(node == NULL) return;
        mp[node->val]++;
        if(node->left == NULL && node->right == NULL){
            int count = 0;
            for(auto it = mp.begin(); it != mp.end(); it++){
                if(it->second % 2 != 0) count++;
            }
            if(count <= 1) ans++;
        }
        solve(node->left);
        solve(node->right);
        if(mp.find(node->val) != mp.end()){
            mp[node->val]--;
            if(mp[node->val] == 0) mp.erase(node->val);
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root);
        return ans;
    }
};
