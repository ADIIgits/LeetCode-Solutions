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
    bool raita_traversal(TreeNode* a,TreeNode* b){
        if(a==NULL && b) return false;
        if(a && b==NULL) return false;
        if(a==NULL && b==NULL) return true;
        if(a->val != b->val) return false;
        return raita_traversal(a->left,b->right)
        && raita_traversal(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return false;
        return raita_traversal(root->left,root->right);
    }
};
