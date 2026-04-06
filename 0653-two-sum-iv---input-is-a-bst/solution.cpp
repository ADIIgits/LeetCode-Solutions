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
    unordered_set<int> seen;
    bool inorder(TreeNode* root,int k){
        if(root==NULL) return false;
        //do i have soln right here and now?
        bool validate = seen.count(k - root->val);
        //insert the current seen node, so that we may check for further nodes.
        seen.insert(root->val);
        //if we have soln right here and now, it will be returned, if no, we will explore.
        return validate || inorder(root->left,k) || inorder(root->right,k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<TreeNode*> vec;
        return inorder(root,k);
    }
};
