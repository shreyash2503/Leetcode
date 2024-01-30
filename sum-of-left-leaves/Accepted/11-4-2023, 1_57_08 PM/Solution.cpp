// https://leetcode.com/problems/sum-of-left-leaves

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
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        if(root->left && root->left->left == NULL && root->left->right == NULL){
            return root->left->val + helper(root->right);
        }

        int l = helper(root->left);
        int r = helper(root->right);

        return l + r;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root);
    }
};