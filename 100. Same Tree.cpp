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
    bool ans = true;
    void solve(TreeNode *p1, TreeNode *q1){
        if(p1 == NULL && q1 != NULL){
            ans = false;
            return;
        }
        if(q1 == NULL && p1 != NULL){
            ans = false;
            return;
        }
        if(p1 == NULL && q1 == NULL){
            return;
        }
        if(ans == false){
            return;
        }
        else if(p1->val == q1->val){
            solve(p1->left,q1->left);
            solve(p1->right,q1->right);
        }
        else{
            ans = false;
            return;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        solve(p,q);
        return ans;
    }
};
