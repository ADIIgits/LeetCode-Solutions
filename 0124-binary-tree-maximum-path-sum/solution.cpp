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
    int pathsum(TreeNode* root,int &maxpathsum){
        if(root==NULL) return 0;
        int hl = pathsum(root->left,maxpathsum);
        int hr = pathsum(root->right,maxpathsum);
        if(hl < 0) hl = 0; if(hr < 0) hr = 0;
        maxpathsum = max(maxpathsum,root->val + hr + hl);
        return max(hl+root->val,hr+root->val);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxpathsum = INT_MIN;
        pathsum(root,maxpathsum);
        return maxpathsum;
    }
};
