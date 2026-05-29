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
    void traverse(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentof,int start, TreeNode* &startnode){
        if(root==NULL) return;

        if(root->left!=NULL) parentof[root->left] = root;
        if(root->right!=NULL) parentof[root->right] = root;
        if(root->val==start) startnode = root;
        traverse(root->left,parentof,start,startnode);
        traverse(root->right,parentof,start,startnode);
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL) return 0;
        unordered_map<TreeNode*,TreeNode*> parentof;
        unordered_map<TreeNode*,bool> vis;
        TreeNode* startnode = NULL;
        traverse(root,parentof,start,startnode);
        queue<pair<TreeNode*,int>> que;
        que.push({startnode,0});
        vis[startnode] = true;
        
        int maxlevel = 0;
        while(!que.empty()){
            auto [rot,level] = que.front();
            que.pop();
            if(rot->left){
                if(!vis[rot->left]){
                    que.push({rot->left,level+1});
                    vis[rot->left] = true;
                }
            }
            if(rot->right){
                if(!vis[rot->right]){
                    que.push({rot->right,level+1});
                    vis[rot->right] = true;
                }
            }
            if(parentof.count(rot)){
                if(!vis[parentof[rot]]){
                    que.push({parentof[rot],level+1});
                    vis[parentof[rot]] = true;
                }
            }
            maxlevel = max(maxlevel,level);
        }
        return maxlevel;
    }
};
