// https://leetcode.com/problems/merge-two-binary-trees

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
    TreeNode* helper(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL){
            return NULL;
        }
        if(root2 == NULL){
            TreeNode* temp = new TreeNode(root1->val);
            temp->left = helper(root1->left, NULL);
            temp->right = helper(root1->right, NULL);
            return temp;
            
        }
        if(root1 == NULL){
            TreeNode* temp = new TreeNode(root2->val);
            temp->left = helper(NULL, root2->left);
            temp->right = helper(NULL, root2->right);
            return temp;
        }
        TreeNode* temp = new TreeNode(root1->val + root2->val);
        temp->left = helper(root1->left, root2->left);
        temp->right = helper(root1->right, root2->right);
        return temp;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return helper(root1, root2);
        
    }
};