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
    int height(TreeNode* root,bool &balanced){
        if(root==NULL) return 0;
        int hl = height(root->left,balanced);
        int hr = height(root->right,balanced);
        if(abs(hl - hr) > 1 && balanced){
            balanced = false;
        }
        return 1 + max(hl,hr);
    }
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        height(root,balanced);
        return balanced;
    }
};
