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
    void solve(TreeNode *node, vector<int> &treeOne){
        if(node == NULL){
            return;
        }
        treeOne.push_back(node->val);
        solve(node->left,treeOne);
        solve(node->right,treeOne);
    }
    void solve1(TreeNode *node, vector<int> &treeTwo){
        if(node == NULL){
            return;
        }
        treeTwo.push_back(node->val);
        solve(node->left,treeTwo);
        solve(node->right,treeTwo);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>treeOne,treeTwo;
        solve(root1,treeOne);
        solve(root2,treeTwo);
        vector<int>res;
        for(int i = 0; i < treeOne.size(); i++) res.push_back(treeOne[i]);
        for(int i = 0; i < treeTwo.size(); i++) res.push_back(treeTwo[i]);
        sort(res.begin(),res.end());
        return res;
    }
};
