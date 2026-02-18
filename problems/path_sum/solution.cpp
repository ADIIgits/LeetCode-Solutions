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
    bool check(TreeNode* root, int sum, int tsum){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL){
            return sum+root->val==tsum;
        }
        int val = root->val;
        return check(root->left,sum+val,tsum) || check(root->right,sum+val,tsum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root,0,targetSum);
    }
};