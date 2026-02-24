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
    int maxsum = INT_MIN;
    int maxpathsum(TreeNode* root){
        if(root==NULL) return 0;
        int left = max(0,maxpathsum(root->left));
        int right = max(0,maxpathsum(root->right));

        
        maxsum = max(maxsum,root->val+left+right);
        return root->val + max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        // maxsum = max(maxsum, currval + leftsum+rightsum)
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        maxpathsum(root);
        return maxsum;
    }
};