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
        queue<TreeNode*> que; que.push(root);
        vector<vector<int>> ans;
        
        while(!que.empty()){
            int levelsize = que.size();
            vector<int> vec;
            for(int i=0;i<levelsize;i++){
                vec.push_back(que.front()->val);
                TreeNode* rot = que.front();
                if(rot->left!=NULL) que.push(rot->left);
                if(rot->right!=NULL) que.push(rot->right);
                que.pop();
            }
            ans.push_back(vec);
        }
        return ans;
    }
};