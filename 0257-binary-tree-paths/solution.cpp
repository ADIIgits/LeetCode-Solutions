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
    void click_paths(TreeNode* root,string path,vector<string> &ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(path+to_string(root->val));
            return;
        }
        click_paths(root->left,path+to_string(root->val)+"->",ans);
        click_paths(root->right,path+to_string(root->val)+"->",ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        click_paths(root,"",ans);
        return ans;
    }
};
