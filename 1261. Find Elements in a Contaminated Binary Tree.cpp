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
class FindElements {
public:
    map<int,int>nodes;
    void restore(TreeNode *node){
        if(node->left == NULL && node->right == NULL) return;
        if(node->left != NULL){
            node->left->val = 2 * node->val + 1;
            restore(node->left);
        }
        if(node->right != NULL){
            node->right->val = 2 * node->val + 2;
            restore(node->right);
        }
    }
    void storeNodes(TreeNode *node){
        if(node == NULL) return;
        storeNodes(node->left);
        nodes[node->val] = 1;
        storeNodes(node->right);
    }
    FindElements(TreeNode* root) {
       root->val = 0; 
       restore(root);
       storeNodes(root); 
    }
    bool find(int target) {
        return nodes[target] == 1;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
