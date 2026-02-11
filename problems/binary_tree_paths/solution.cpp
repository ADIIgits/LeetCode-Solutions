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
    void btpaths(TreeNode* root,vector<string> &ans,string s){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s+to_string(root->val));
            return;
        }
        btpaths(root->left,ans,s+to_string(root->val)+"->");
        btpaths(root->right,ans,s+to_string(root->val)+"->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        btpaths(root,ans,"");
        return ans;
    }
};