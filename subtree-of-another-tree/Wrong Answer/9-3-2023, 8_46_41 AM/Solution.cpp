// https://leetcode.com/problems/subtree-of-another-tree

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
    bool helper(TreeNode* root, TreeNode* subRoot){
        if(root == NULL){
            return false;

        }
        if(root == subRoot){
            if(root->left == NULL && root->right== NULL){
                if(subRoot->left == NULL && subRoot->right == NULL){
                    return true;
                } else {
                    return false;
                }
            }
            return helper(root->right, subRoot->right) && helper(root->left, subRoot->left);
            
        }
        int l = helper(root->left, subRoot);
        int r = helper(root->right, subRoot);
        if(l == true){
            return true;
        }
        if(r == true){
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root, subRoot);

        
    }
};