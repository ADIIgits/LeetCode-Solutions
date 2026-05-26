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
    map<int,vector<pair<int,int>>> map;
    void vt(TreeNode* root,int row,int col){
        if(root==NULL) return;
        map[col].push_back({row,root->val});
        vt(root->left,row+1,col-1);
        vt(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vt(root,0,0);
        for(auto [col,data]:map){
            sort(data.begin(),data.end());
            vector<int> vec;
            for(auto [row,val]:data) vec.push_back(val);
            ans.push_back(vec);
        }
        return ans;
    }
};
