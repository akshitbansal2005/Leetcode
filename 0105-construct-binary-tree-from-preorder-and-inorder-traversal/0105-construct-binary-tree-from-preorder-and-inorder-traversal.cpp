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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int preStart, int preEnd,int inStart, int inEnd) {
        if(preStart > preEnd || inStart > inEnd) {
            return NULL;
        }
        // preorder is root -> left -> right
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = -1;
        // inorder is left -> root -> right
        for(int i = inStart; i <= inEnd; i++) {
            if(inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }
        int leftNodes = rootIndex - inStart;
        root->left = solve(preorder, inorder,preStart + 1,preStart + leftNodes,inStart,rootIndex - 1);
        root->right = solve(preorder, inorder,preStart + leftNodes + 1, preEnd, rootIndex + 1,inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0) {
            return NULL;
        }
        return solve(preorder, inorder,0, n - 1,0,n-1);
    }
};