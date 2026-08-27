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


/* so we need to check the largest bst in example 1-> 1,4,3,2,4,2,5,null,null,null,null,null,null,4,6
    larget bst is 3,2,5,4,6 and its sum is 20 because if we can see root is 1 and its right should be greater 
    than the root val so 3 is greater and if we check the left its 4 so the right one if we take the sum to uska 
    sum is 4,2,4->10 which is less than the sum of 3,2,5,4,6 so we can clearly see which side is maximum 
    */
// class NodeValue {
// public:
//     int maxNode,minNode, maxSize;
//     NodeValue(int minNode, int maxNode, int maxSize){
//         this->maxNode=maxNode;
//         this->minNode=minNode;
//         this->maxSize=maxSize;

//     }
// };
// class Solution {
// private: 
//     NodeValue maxSumBSTHelper(TreeNode* root){
//         if(root==NULL){
//             return NodeValue(INT_MAX, INT_MIN, 0);
//         }
//         auto left=maxSumBSTHelper(root->left);
//         auto right=maxSumBSTHelper(root->right);
//         if(left.maxNode<root->val && root->val<right.minNode){
//             return NodeValue(min(root->val,left.minNode), max(root->val, right.maxNode), left.maxSize+right.maxSize+1);
//         }
//         return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));


//     }
//     public:
//     int maxSumBST(TreeNode* root) {
//         return maxSumBSTHelper(root).maxSize;
        
//     }
// };


/*
The main idea: for every node, return min, max, and sum of the subtree.
 If the left maximum is smaller than the current node and the current node 
 is smaller than the right minimum, the subtree is a BST
 */


class NodeValue {
public:
    int minNode;
    int maxNode;
    int sum;
    NodeValue(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};
class Solution {
private:
    int ans = 0;
    NodeValue solve(TreeNode* root) {
        if (root== NULL) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        NodeValue left = solve(root->left);
        NodeValue right = solve(root->right);
        if (left.maxNode < root->val &&
            root->val < right.minNode) {
            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);
            int mn = min(root->val, left.minNode);
            int mx = max(root->val, right.maxNode);

            return NodeValue(mn, mx, currSum);
        }
        return NodeValue(INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};

