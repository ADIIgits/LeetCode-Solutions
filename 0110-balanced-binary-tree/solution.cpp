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
    int maxdepth(TreeNode* root,bool &isbalanced){
        if(root==NULL) return 0;
        int left = maxdepth(root->left,isbalanced);
        int right = maxdepth(root->right,isbalanced);
        if(abs(left-right) > 1 && isbalanced){
            isbalanced = false;
            return 0; //we just wanna return, we dont care calc happens now, cux it aint balanced !!
        }
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool isbalanced = true;
        maxdepth(root,isbalanced);
        return isbalanced;
    }
};
