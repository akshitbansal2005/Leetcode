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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {


        // inorder is left->root->right
        // postorder is root->left->right
        if(inorder.size()!=postorder.size()) return NULL;
        map<int, int>mpp;
        for(int i =0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return buildTreePostIn(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);

    }



    // ps->starting point of postorder
    // ie->ending point of inorder
    // pe->ending point of postorder
    // is -> starting point of inorder


    TreeNode* buildTreePostIn(vector<int>&inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int>&mpp){
        if(ps>pe||is>ie) return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        
        int inRoot=mpp[postorder[pe]];
        int numsLeft=inRoot-is;

        root->left =buildTreePostIn(inorder, is,inRoot-1, postorder,ps,ps+numsLeft-1, mpp);


        root->right =buildTreePostIn(inorder, inRoot+1,ie, postorder,ps+numsLeft,pe-1, mpp);
        return root;

    }
};