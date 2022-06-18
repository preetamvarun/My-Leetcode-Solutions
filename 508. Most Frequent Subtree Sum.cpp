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
    map<int,int>mp;
    TreeNode *temp;
    int solve(TreeNode *node){
        if(node == NULL) return 0;
        int left_sum = solve(node->left);
        int right_sum = solve(node->right);
        mp[node->val + left_sum + right_sum]++;
        return node->val + left_sum + right_sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        solve(root);
        int val = INT_MIN;
        for(auto it = mp.begin(); it != mp.end(); it++) val = max(val,it->second);
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second == val) ans.push_back(it->first);
        }
        return ans;
    }
};
