// https://leetcode.com/problems/univalued-binary-tree

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
    bool helper(TreeNode* root, int value){
        if(root == NULL){
            return true;
        }
        if(root->val == value){
            return helper(root->left, value) && helper(root->right, value);
        }
        return false;
    }
    bool isUnivalTree(TreeNode* root) {
        int value = root->val;
        return helper(root, value);
        
    }
};