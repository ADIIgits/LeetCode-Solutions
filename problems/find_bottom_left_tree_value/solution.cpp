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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int ans=0;
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            for(int i=0;i<size;i++){
                TreeNode* rot = que.front();
                que.pop();
                if(rot->left) que.push(rot->left);
                if(rot->right) que.push(rot->right);
                vec.push_back(rot->val);
            }
            ans = vec[0];
        }
        return ans;
    }
};