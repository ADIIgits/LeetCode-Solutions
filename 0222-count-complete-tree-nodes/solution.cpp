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
    int count_depth(TreeNode* root,int dir){
        int c = 0;
        while(root!=NULL){
            root = dir == 0 ? root->left : root->right;
            c++;
        }
        return c;
    }
    int countnode(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + countnode(root->left) + countnode(root->right);
    }
    int countNodes(TreeNode* root) {
        int left = count_depth(root,0);
        int right = count_depth(root,1);
        if(left==right) return pow(2,left) - 1;
        return 1 + countnode(root->left) + countnode(root->right);
    }
};
