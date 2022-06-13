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
    TreeNode *ans = NULL;
    void search(TreeNode *node,int val){
        if(node == NULL || ans != NULL){
            return;
        }
        else if(val > node->val && ans == NULL){
            search(node->right,val);
        }
        else if(val < node->val && ans == NULL){
            search(node->left,val);
        }
        else{
            ans = node;
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        search(root,val);
        return ans;
    }
};
