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
        if(isbalanced==false) return 0;
        int heightleft = height(root->left);
        int heightright = height(root->right);
        if(isbalanced==true) isbalanced = abs(heightleft - heightright) <= 1;
        return 1 + max(heightleft,heightright);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        int h = height(root);
        return isbalanced;
    }
};