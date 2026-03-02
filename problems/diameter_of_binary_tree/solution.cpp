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
    int diameter = 0;
    int maxheight(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int leftheight = maxheight(root->left);
        int rightheight = maxheight(root->right);
        diameter = max(diameter,leftheight+rightheight);
        return 1 + max(leftheight,rightheight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxheight(root);
        return diameter;
    }
};