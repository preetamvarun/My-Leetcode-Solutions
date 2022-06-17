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
    void solve(TreeNode *node, vector<int> &nodes){
        if(node == NULL) return;
        if(node->val % 2 == 0){
            if(node->left != NULL){
                TreeNode *x = node->left;
                if(x->left != NULL) nodes.push_back(x->left->val);
                if(x->right != NULL) nodes.push_back(x->right->val);
            }
            if(node->right != NULL){
                TreeNode *x = node->right;
                if(x->left != NULL) nodes.push_back(x->left->val);
                if(x->right != NULL) nodes.push_back(x->right->val);
            }
        }
        solve(node->left,nodes);
        solve(node->right,nodes);
    }
    int sumEvenGrandparent(TreeNode* root) {
        vector<int>nodes;
        solve(root,nodes);
        int ans = 0;
        for(int i = 0; i < nodes.size(); i++){
            ans += nodes[i];
        }
        return ans;
    }
};
