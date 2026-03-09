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
    TreeNode* groundzero=NULL;
    TreeNode* preorder(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &map,int start){
        if(root==NULL) return NULL;
        if(root->val==start) groundzero = root;
        // if(root->left==NULL && root->right==NULL) return root;
        TreeNode* left = preorder(root->left,map,start);
        TreeNode* right = preorder(root->right,map,start);
        if(left) map[left]=root;
        if(right) map[right]=root;
        return root;
    }
    int infect(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &map){
        if(groundzero==NULL) return -1;
        queue<TreeNode*> que;
        unordered_map<TreeNode*,bool> visited;
        que.push(groundzero);
        visited[groundzero]=true;
        int minute=0;
        
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* rot = que.front();
                if(rot->left && !visited[rot->left]){
                    visited[rot->left]=true;
                    que.push(rot->left);
                }
                if(rot->right && !visited[rot->right]){
                    visited[rot->right]=true;
                    que.push(rot->right);
                }
                if(map[rot] && !visited[map[rot]]){
                    visited[map[rot]]=true;
                    que.push(map[rot]);
                }
                que.pop();
            }
            minute++;
        }
        return minute-1;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> map;
        preorder(root,map,start);
        return infect(root,map);
    }
};