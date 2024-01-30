// https://leetcode.com/problems/invert-binary-tree

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
    void helper(TreeNode* root){
        if(root == NULL){
            return;
        }
        TreeNode* temp = root;
        TreeNode* flag = temp->right;
        temp->right = temp->left;
        temp->left = flag;
        helper(temp->left);
        helper(temp->right);

    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
        
    }
};