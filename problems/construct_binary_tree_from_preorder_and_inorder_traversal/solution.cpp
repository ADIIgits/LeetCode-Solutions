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
    TreeNode* buildtree(vector<int>& preorder, int pstart,int pend, vector<int>& inorder,int istart,int iend){
        int n = preorder.size();
        if(pstart>pend) return NULL;
        TreeNode* root = new TreeNode(preorder[pstart]);
        int i = istart;
        while(inorder[i]!=preorder[pstart]) i++;
        int leftsize = i-istart;
        root->left =  buildtree(preorder,pstart+1, pstart+leftsize,inorder,istart,i-1);
        root->right =  buildtree(preorder,pstart+leftsize+1,pend,inorder,i+1,iend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode* root = buildtree(preorder,0,n-1,inorder,0,n-1);
        return root;
    }
};