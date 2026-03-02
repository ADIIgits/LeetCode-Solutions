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
    int maxdepth(TreeNode* root){
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL) return 1;
        return 1 + max(maxdepth(root->left),maxdepth(root->right));
    }


public:
    int maxDepth(TreeNode* root) {
        return maxdepth(root);
    }
};