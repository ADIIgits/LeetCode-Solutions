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
    TreeNode* deletenode(TreeNode* root, int key){
        if(root==NULL) return NULL;
        // if(root->val==key) return NULL;

        else if(root->val > key) root->left = deletenode(root->left,key);
        else if(root->val < key) root->right = deletenode(root->right,key);
        else { //rootval==key, so you wanna delete root and return updated tree.

            if(root->left==NULL && root->right==NULL) return NULL; 
            //why return NULL and not root? cuz you wanna delete da root
            if(root->left==NULL) return root->right; 
            //why rreturn root->right and not root? cuz you wanna delete da root
            if(root->right==NULL) return root->left;

            //both right and left are non nulls
            //since the root must be deleted, someone must take its place and it will be its predecessor.
            //finding predecessor of current node (ie root)., 
            //you do that shi by going all the way to right of the left node 
            //(take the leftnode, go all the way to right)
            TreeNode* pred = root->left;
            while(pred->right!=NULL) pred = pred->right;

            //but before replacing root with predeccessor, we must first delete predessor. we cant have 2 of em.
            root->left = deletenode(root->left,pred->val);
            //then we simply crown the lefts and rights of currentnode(root) to this predecessor, 
            //which technically means its the new currentnode(root).
            pred->left = root->left;
            pred->right = root->right;
            return pred;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deletenode(root,key);
    }
};
