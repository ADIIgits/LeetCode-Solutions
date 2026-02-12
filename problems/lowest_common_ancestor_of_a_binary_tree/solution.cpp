/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* found(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        
        TreeNode* leftf = found(root->left,p,q);
        TreeNode* rightf = found(root->right,p,q);

        if(leftf && rightf) return root;
        else if(leftf) return leftf;
        else if(rightf) return rightf;
        else return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return found(root,p,q);
    }
};