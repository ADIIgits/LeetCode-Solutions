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
    void capture(TreeNode* root,vector<TreeNode*> &nodes){
        if(root==NULL) return;
        capture(root->left,nodes);
        nodes.push_back(root);
        capture(root->right,nodes);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        capture(root,nodes);
        int sum = 0; int n = nodes.size();
        for(int i=n-1;i>=0;i--){
            TreeNode* node = nodes[i];
            sum+=node->val;
            node->val = sum;
        }
        return root;
    }
};
