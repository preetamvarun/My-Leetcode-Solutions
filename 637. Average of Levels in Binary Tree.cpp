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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        vector<vector<long int>>levels;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            long int k = q.size();
            vector<long int>level;
            for(long int i = 0; i < k; i++){
                level.push_back(q.front()->val);
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
            levels.push_back(level);
        }
        for(long int i = 0; i < levels.size(); i++){
            long int sum = 0;
            vector<long int>x = levels[i];
            for(long int j = 0; j < x.size(); j++){
                sum += x[j];
            }
            double val = (double)sum / x.size();
            // cout << sum << " " << x.size() << " " << val << endl;
            ans.push_back(val);
        }
        return ans;
    }
};
