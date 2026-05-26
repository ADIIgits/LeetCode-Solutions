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
    void weird_traverse(TreeNode* root,vector<int> &ans,int &deepest_row,int row){
        if(root==NULL) return;
        if(deepest_row < row){
            deepest_row = row;
            ans.push_back(root->val);
        }
        weird_traverse(root->right,ans,deepest_row,row+1);
        weird_traverse(root->left,ans,deepest_row,row+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        //always make right call first
        //if row bigger, print
        //basically make it always the right call that goes to deeper level, print and update deepest level
        vector<int> ans;
        int deepest_row = -1;
        weird_traverse(root,ans,deepest_row,0);
        return ans;
    }
};
