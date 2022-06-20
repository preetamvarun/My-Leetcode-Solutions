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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>mp;
        while(q.size()){
            int k = q.size();
            for(int i = 0; i < k; i++){
                TreeNode *node = q.front().first;
                int vertical = q.front().second.first;
                int level = q.front().second.second;
                q.pop();
                if(node->left) q.push({node->left,{vertical-1,level+1}});
                if(node->right) q.push({node->right,{vertical+1,level+1}});
                mp[vertical][level].insert(node->val);
            }
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            map<int,multiset<int>>mp_in = it->second;
            vector<int>v;
            for(auto x = mp_in.begin(); x != mp_in.end(); x++){
                multiset<int>s = x->second;
                for(auto ite = s.begin(); ite != s.end(); ite++){
                    v.push_back(*ite);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
