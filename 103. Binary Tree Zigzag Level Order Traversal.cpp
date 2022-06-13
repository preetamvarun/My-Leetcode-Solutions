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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        bool go_rev = false;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int k = q.size();
            vector<int>nodes;
            for(int i = 0; i < k; i++){
                nodes.push_back(q.front()->val);
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
            if(!go_rev){
                go_rev = true;
                ans.push_back(nodes);
            }
            else{
                go_rev = false;
                reverse(nodes.begin(),nodes.end());
                ans.push_back(nodes);
            }
        }
        return ans;
    }
};
