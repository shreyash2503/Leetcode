// https://leetcode.com/problems/path-sum

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
    bool helper(TreeNode* root, int targetSum, int sum){
        if(root == NULL){
            return false;
        }
        if(sum + root->val == targetSum && root->left == NULL && root->right == NULL){
            return true;
        }
        if(helper(root->left, targetSum, sum + root->val)){
            return true;
        }
        if(helper(root->right, targetSum, sum + root->val)){
            return true;
        }
        return false;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return helper(root, targetSum, sum);
        
    }
};