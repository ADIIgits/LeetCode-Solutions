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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        stack<TreeNode*> st; st.push(root);
        while(!st.empty()){
            TreeNode* rot = st.top();
            ans.push_back(rot->val);
            st.pop();
            if(rot->right) st.push(rot->right);
            if(rot->left) st.push(rot->left);
            
            
        }
        return ans;

    }
};