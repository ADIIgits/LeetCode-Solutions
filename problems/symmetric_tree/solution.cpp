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
    
    bool traverse(TreeNode* a,TreeNode* b){
        if(a==NULL && b==NULL) return true;
        if(a!=NULL && b==NULL) return false;
        if(a==NULL && b!=NULL) return false;
        if(a->val!=b->val){
            // ans=false;
            return false;
        }
        bool left = traverse(a->left,b->right);
        bool right =  traverse(a->right,b->left);
        return left && right;
        
    }

public:
    bool isSymmetric(TreeNode* root) {
        
        return traverse(root->left,root->right);
       
        
    }
};