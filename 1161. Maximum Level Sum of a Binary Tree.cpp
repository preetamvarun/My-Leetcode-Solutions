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

    int maxLevelSum(TreeNode* root) {

        int ans = 0;

        vector<vector<int>>res;

        if(root == NULL){

            return ans;

        }

        queue<TreeNode*>q;

        q.push(root);

        vector<vector<int>>vec; int maxLevel = INT_MIN;

        while(q.size()){

            int k = q.size(), v = 0;

            vector<int>x;

            for(int i = 0; i < k; i++){

                TreeNode *node = q.front();

                q.pop();

                v += node->val;

                x.push_back(node->val);

                if(node->left != NULL) q.push(node->left);

                if(node->right != NULL) q.push(node->right);

            }

            maxLevel = max(maxLevel,v);

            res.push_back(x);

        }

        for(int i = 0; i < res.size(); i++){

            vector<int>temp = res[i];

            int compute = 0;

            for(int y = 0; y < temp.size(); y++){

                compute += temp[y];

            }

            if(compute == maxLevel){

                ans = i + 1;

                break;

            }

        }

        return ans;

    }

};
