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

/* to ek baar question ke example ko dekh kr ye pata chal gya ki what bst really is 
  i mean ki jo main node ke right wali value of hogi vo hamesha badi hogi as compared 
  to main node and jo left value hogi vo small hogi which makes a valid bst 

  ahhh jo mei soch raha tha vo half he correct, jo logic mei likh raha tha usse error 
  aagya 

  to iss baar ky krege ki 3 variables banege first,second, third sabko null rakh dege 
  iske baad ky hoga ki agar first =null hua to first =prev element hoga and second bann 
  jayega root elem otherwise prev ==root and in main function will swap both left and right element 
*/     
class Solution {
public:
    TreeNode* first=NULL,*second=NULL, *prev=NULL;
    void RT(TreeNode* root){
        if(root==NULL) return;
        // int temp = root->left;
        // TreeNode* right=root->right->val;
        // TreeNode* left=root->left->val;
        // root->left=root->val;
        // root->val=root->right
        // if(root->val >root->right->val|| root->val <root->left->val){
        // }
        RT(root->left);
        if(prev &&prev->val >root->val){
            if(first==NULL){
                first=prev;
            }
            second=root;

        }
        prev=root;
        RT(root->right);
    }
    void recoverTree(TreeNode* root) {
        RT(root);
        swap(first->val, second->val);
    }
};