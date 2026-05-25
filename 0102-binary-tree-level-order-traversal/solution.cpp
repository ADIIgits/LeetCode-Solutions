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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            
            vector<int> vec;
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* rot = que.front();
                que.pop();
                vec.push_back(rot->val);
                if(rot->left) que.push(rot->left);
                if(rot->right) que.push(rot->right);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
