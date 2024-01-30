// https://leetcode.com/problems/delete-leaves-with-a-given-value

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

    bool helper(TreeNode* root, int target){
        if(root == NULL){
            return false;
        }

        if(helper(root->left, target)){
            root->left = NULL;
        }
        if(helper(root->right, target)){
            root->right = NULL;
        }

        if(root->left == NULL && root->right == NULL && root->val == target){
            return true;
        }
        return false;


    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* temp = root;
        helper(temp, target);
        return temp;
        
    }
};