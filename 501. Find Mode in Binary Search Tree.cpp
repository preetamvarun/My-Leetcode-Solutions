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
    void solve(TreeNode *node,map<int,int> &mp){
        if(node == NULL) return;
        mp[node->val]++;
        solve(node->left,mp);
        solve(node->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int>mp;
        solve(root,mp);
        vector<int>ans; int x = INT_MIN;
        for(auto it = mp.begin(); it != mp.end(); it++){
            x = max(x,it->second);
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second == x){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
