// https://leetcode.com/problems/insert-into-a-binary-search-tree

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

    void helper(TreeNode* root, int val){
        if(root == NULL){

            return;
        }

        if(root->val > val){
            if(root->left == NULL){
                TreeNode* node = new TreeNode(val);
                root->left = node;
                return;
            }
            helper(root->left, val);
            return;
        }
        if(root->val  < val){
            if(root->right == NULL){
                TreeNode* node = new TreeNode(val);
                root->right = node;
                return;
            }
            helper(root->right, val);
            return;
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        auto temp = root;

        helper(temp, val);

        return root;

        
        
    }
};