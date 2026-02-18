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
    void preorder(TreeNode* root,vector<TreeNode*> &nodes){
        if(root==NULL) return;
        nodes.push_back(root);
        if(root->left) preorder(root->left,nodes);
        if(root->right) preorder(root->right,nodes);
    }
    
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        preorder(root,nodes);
        int n = nodes.size();
        for(int i=0;i<n-1;i++){
            TreeNode* rot = nodes[i];
            rot->left=NULL;
            rot->right = nodes[i+1];
        }
    }
};