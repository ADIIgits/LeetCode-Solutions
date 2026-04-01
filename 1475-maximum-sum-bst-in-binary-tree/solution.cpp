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
    int maxsum = 0;
    class Info{
        public:
        int sum=0;
        int maxi = 0;
        int mini = 0;
        bool isbst=false;
    };
    Info calcmaxsum(TreeNode* root){
        //every node sends a reportcard back to parent
        if(root==NULL){
            Info newroot;
            newroot.sum=0;
            newroot.maxi=INT_MIN;
            newroot.mini=INT_MAX;
            newroot.isbst=true;
            return newroot;
        }
        Info newroot;
         
        Info left = calcmaxsum(root->left);
        Info right = calcmaxsum(root->right);
        newroot.isbst = left.isbst && right.isbst && (left.maxi < root->val && root->val < right.mini);
        newroot.sum = root->val + left.sum + right.sum;

        newroot.maxi = max(root->val,max(left.maxi,right.maxi));
        newroot.mini = min(root->val,min(left.mini,right.mini));

        if(newroot.isbst) maxsum = max(maxsum,newroot.sum);
        return newroot;
    }
    int maxSumBST(TreeNode* root) {
        //traverse watchout for sums, while passing is its bst or not, 
        //every node sends a reportcard back to parent
        calcmaxsum(root);
        return maxsum;

    }
};
