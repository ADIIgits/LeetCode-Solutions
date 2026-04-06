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
    void inorder(TreeNode* root,vector<TreeNode*> &vec){
        if(root==NULL) return;
        if(root->left) inorder(root->left,vec);
        vec.push_back(root);
        if(root->right) inorder(root->right,vec);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> vec;
        inorder(root,vec);
        cout<<vec.size();
        TreeNode* first = NULL; TreeNode* second = NULL;
        TreeNode* prev = NULL;
        for(TreeNode* node:vec){
            if(prev!=NULL && prev->val > node->val){
                if(first==NULL) first = prev;
                second = node;
            }
            prev=node;
        }
        if(first!=NULL && second!=NULL) swap(first->val,second->val);
    }
};
