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
    void checksum(TreeNode* root,vector<vector<int>> &ans, vector<int> vec,int tsum,int sum){
        if(root==NULL) return;
        if(root->left==NULL  && root->right==NULL){
            vec.push_back(root->val);
            if(tsum==sum+root->val) ans.push_back(vec);
        }
        vec.push_back(root->val);
        if(root->left) checksum(root->left,ans,vec,tsum,sum+root->val);
        if(root->right) checksum(root->right,ans,vec,tsum,sum+root->val);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> vec;
        checksum(root,ans,vec,targetSum,0);
        return ans;
    }
};