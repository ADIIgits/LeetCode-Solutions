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
    void traverse(TreeNode* root,pair<int,int> &data,int row){
        if(root==NULL) return;
        //for every level you make 2 calls, left thne. right.
        //you make left call first + you only update the data when you reach a level strictly greater, 
        //so for any level, left call updates the data first. and then it cant be updated by the right call for same level.
        //thus you get leftmost value of deepest level.
        if(data.first < row){
            data.first = row;
            data.second = root->val;
        }
        traverse(root->left,data,row+1);
        traverse(root->right,data,row+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        pair<int,int> data = {-1,-1};
        traverse(root,data,0);
        return data.second;
    }
};
