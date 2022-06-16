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
    void solve(TreeNode *node,vector<int> &ds){
        if(node == NULL) return;
        ds.push_back(node->val);
        solve(node->left,ds);
        solve(node->right,ds);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ds;
        solve(root,ds);
        map<int,int>mp;
        for(int i = 0; i < ds.size(); i++){
            if(i == 0){
                mp[ds[i]] = 1;
            }
            else{
                if(mp.find(k-ds[i]) != mp.end()){
                    return true;
                }
                else{
                    mp[ds[i]] = 1;
                }
            }
        }
        return false;
    }
};
