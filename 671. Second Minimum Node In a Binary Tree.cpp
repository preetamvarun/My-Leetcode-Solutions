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
    void solve(TreeNode *node,map<int,int>&mp){
        if(node == NULL) return;
        mp[node->val]++;
        solve(node->left,mp);
        solve(node->right,mp);
    }
    int findSecondMinimumValue(TreeNode* root) {
        map<int,int>mp;
        solve(root,mp);
        mp.erase(mp.begin());
        if(mp.size() == 0) return -1;
        return mp.begin()->first;
    }
};
