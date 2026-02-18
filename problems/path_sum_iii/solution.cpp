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
    int count=0;
    void traverse(TreeNode* root, long long sum,int tsum){
        if(root==NULL) return;
        sum+=root->val;
        
        if(sum==tsum) count++;
        traverse(root->left,sum,tsum);
        traverse(root->right,sum,tsum);
    }
    void pathsum(TreeNode* root,int tsum){
        if(root==NULL) return;
        traverse(root,0,tsum);
        pathsum(root->left,tsum);
        pathsum(root->right,tsum);
        
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        pathsum(root,targetSum);
        // traverse(root,0,targetSum);
        return count;
    }
};