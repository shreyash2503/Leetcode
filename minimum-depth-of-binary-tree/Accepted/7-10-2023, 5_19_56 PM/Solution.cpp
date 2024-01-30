// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int rightSide = 1;
        int leftSide = 1;
       if(root->right){
           rightSide = minDepth(root->right) + 1;
           
       }
       if(root->left){
           leftSide = minDepth(root->left) + 1;
       }
       if(rightSide == 1){
           return leftSide;
       }
       if(leftSide == 1){
           return rightSide;
       }
       return min(leftSide, rightSide);
    }
};