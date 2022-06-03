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

    int deepestLeavesSum(TreeNode* root) {

        int ans = 0;

        vector<vector<int>>levelNodes;

        if(root == NULL){

            return 0;

        }

        queue<TreeNode*>q;

        q.push(root);

        while(q.size()){

            int k = q.size();

            vector<int>currLevelNodes;

            for(int i = 0; i < k; i++){

                TreeNode *node = q.front();

                q.pop();

                if(node->left != NULL) q.push(node->left);

                if(node->right != NULL) q.push(node->right);

                currLevelNodes.push_back(node->val);

            }

            levelNodes.push_back(currLevelNodes);

        }

        vector<int>leafNodes = levelNodes[levelNodes.size()-1];

        for(int i = 0; i < leafNodes.size(); i++) ans += leafNodes[i];

        return ans;

    }

};
