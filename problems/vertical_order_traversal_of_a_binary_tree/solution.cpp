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
    int left = INT_MAX;
    int right = INT_MIN;
    unordered_map<int,vector<vector<int>>> map;
    void traverse(TreeNode* root,int row,int col){
        if(root==NULL) return;
        left = min(left,col);
        right = max(right,col);
        map[col].push_back({col,row,root->val});
        if(root->left) traverse(root->left,row+1,col-1);
        if(root->right) traverse(root->right,row+1,col+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root,0,0);
        vector<vector<int>> ans;
        for(int i=left;i<=right;i++){
            vector<vector<int>> vec = map[i];
            sort(vec.begin(),vec.end());
            vector<int> vc;
            for(vector<int> trip:vec){
                vc.push_back(trip.back());
            }
            ans.push_back(vc);
        }
        return ans;
    }
};