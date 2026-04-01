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
    void save(TreeNode* root,vector<TreeNode*> &vec){
        if(root==NULL) return;
        if(root->right) save(root->right,vec);
        vec.push_back(root);
        if(root->left) save(root->left,vec);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> vec;
        save(root,vec);
        int sum=0;
        for(TreeNode* node:vec){
            sum+=node->val;
            node->val = sum;
        }
        return root;
    }
};
