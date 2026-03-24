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
    void insertnode(TreeNode* root, int val){
        if(root==NULL) return;
        
        if(root->val <= val){
            if(root->right==NULL) {
                root->right = new TreeNode(val);
                return;
            }
            else insertnode(root->right,val);
        } 
        else if(root->val >= val){
            if(root->left==NULL){
                root->left = new TreeNode(val);
                return;
            }
            else insertnode(root->left,val);
        } 
        return;
    }
    int search(TreeNode* root, int val){
        if(root==NULL) return false;
        else if(root->val==val) return true;
        else if(root->val < val) return search(root->right,val);
        else if(root->val > val) return search(root->left,val);
        else return false;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return root = new TreeNode(val);
        if(search(root,val)) return root;
        insertnode(root,val);
        return root;
    }
};