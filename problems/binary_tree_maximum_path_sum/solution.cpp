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
    int maxpathsum = INT_MIN;
    int pathsum(TreeNode* root){
        if(root==NULL) return 0;
        // if(root->left==NULL && root->right==NULL) return root->val;
        int leftsum = pathsum(root->left);
        int rightsum = pathsum(root->right);
        if(leftsum<0) leftsum=0; if(rightsum<0) rightsum=0;
        int sum = leftsum+rightsum+root->val;
        maxpathsum = max(maxpathsum,sum);
        return max(leftsum+root->val,rightsum+root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        pathsum(root);
        return maxpathsum;
    }
};