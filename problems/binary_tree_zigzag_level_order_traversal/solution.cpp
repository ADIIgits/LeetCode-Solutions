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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> que; que.push(root);
        vector<vector<int>> ans;
        bool forward = true; 
        while(!que.empty()){
            int n = que.size();
            vector<int> vec(n);
            for(int i=0;i<n;i++){
                TreeNode* rot = que.front();
                if(forward) vec[i] = rot->val;
                else vec[n-i-1] = rot->val;
                if(rot->left) que.push(rot->left);
                if(rot->right) que.push(rot->right);
                que.pop();
            }
            forward = !forward;
            ans.push_back(vec);
        }
        return ans;

    }
};