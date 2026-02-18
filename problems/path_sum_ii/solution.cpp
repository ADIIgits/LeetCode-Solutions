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
    void check(TreeNode* root,vector<vector<int>> &paths,vector<int> &vec,int sum,int tsum){
        if(root==NULL) return;
        sum+=root->val;
        vec.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==tsum) paths.push_back(vec);
        }
        check(root->left,paths,vec,sum,tsum);
        check(root->right,paths,vec,sum,tsum);
        vec.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> vec;
        check(root,paths,vec,0,targetSum);
        return paths;
    }
};