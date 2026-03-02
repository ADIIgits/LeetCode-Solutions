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
    bool isbalanced = true;
    int height(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        if(isbalanced==true) isbalanced = abs(leftheight-rightheight) <= 1;
        return 1 + max(leftheight,rightheight);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        height(root);
        return isbalanced;
    }
};