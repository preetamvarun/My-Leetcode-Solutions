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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>levels;
        if(root == NULL) return levels;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            long int k = q.size();
            vector<int>level;
            for(int i = 0; i < k; i++){
                level.push_back(q.front()->val);
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
            levels.insert(levels.begin()+0,level);
        }
        return levels;
    }
};
