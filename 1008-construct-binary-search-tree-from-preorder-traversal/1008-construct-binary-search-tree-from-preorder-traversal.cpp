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

    /* Preorder is root->left->right   

     what am i thinking is that agar mei right aur left node bana leta hu 
      and unko compare krta hu main root se aur agar main root se less than 
      hoga to left jayega and agar greater hoga to right jayega standard preorder 
      traversal might work here ig 

      basic intilization failed but after making another function in which i had 
      compare val and left and right roots and return accordingly and 
      return it */


    TreeNode* bstFromPreorder(vector<int>& preorder,TreeNode* root, int val) {
        if(root==NULL) {
            return new TreeNode(val);
        }
        if(val<root->val) {
            root->left =bstFromPreorder(preorder,root->left,val);
        }
        else {
            root->right =bstFromPreorder(preorder,root->right,val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // int val = root->val;
        // TreeNode* root=root->val;
        // TreeNode* right=root->right;
        // TreeNode* left=root->left;
        // if(root == NULL) return NULL;
        // if(val==root->val ) return root;
        // else if(val<root->val) return bstFromPreorder(root->left,val);
        // else return bstFromPreorder (root->right,val);
        // return root;

        int p=preorder.size();
        TreeNode* root = NULL;
        for(int i=0;i<p;i++) {
            root = bstFromPreorder(preorder,root,preorder[i]);
        }
        return root;
    }
};