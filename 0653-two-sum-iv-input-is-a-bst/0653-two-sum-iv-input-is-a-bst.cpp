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


/* so what question is trying to say is that agar 2 int ka sum agar == K(given value)
ke hoga to true print kro otherwise false print kro
but mei ky soch raha hu ki ek function banatein h aur usme dfs(depth first search)
 krege extreme left and right jaake dekhege*/
    unordered_set<int>seen;
    bool dfs(TreeNode* root, int k) {
        if(root==NULL) return false;
        if(seen.count(k-root->val)) return true;
        seen.insert(root->val);
        return dfs(root->left,k) ||dfs(root->right,k);

    }
    bool findTarget(TreeNode* root, int k) {
        return dfs(root,k);
    }
};