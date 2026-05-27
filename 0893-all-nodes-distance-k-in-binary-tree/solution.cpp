/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root,unordered_map<int,vector<int>> &map){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            return;
        }
        if(root->left==NULL){
            map[root->right->val].push_back(root->val);
            map[root->val].push_back(root->right->val);
        }
        else if(root->right==NULL){
            map[root->left->val].push_back(root->val);
            map[root->val].push_back(root->left->val);
        }
        else if(root->left!=NULL && root->right!=NULL){
            map[root->right->val].push_back(root->val);
            map[root->val].push_back(root->right->val);
            map[root->left->val].push_back(root->val);
            map[root->val].push_back(root->left->val);
        }
        
        traverse(root->left,map);
        traverse(root->right,map);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> map;
        vector<int> ans;
        traverse(root,map);
        queue<pair<int,int>> que;
        unordered_map<int,bool> vis;
        que.push({target->val,0});
        vis[target->val] = true;
        
        while(!que.empty()){
            auto [rotnode,level] = que.front();
            
            que.pop();
            for(int node:map[rotnode]){
               if(!vis[node]){
                vis[node] = true;
                que.push({node,level+1});
               }
            }
            if(level==k) ans.push_back(rotnode);
        }
        return ans;
    }
};
