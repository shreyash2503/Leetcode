// https://leetcode.com/problems/evaluate-boolean-binary-tree

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
    bool helper(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        if(root->val == 2){
            return right || left;
        }
        if(root->val == 3){
            return right && left;
        }
        return 1;

    }
    bool evaluateTree(TreeNode* root) {
        return helper(root);
        
    }
};