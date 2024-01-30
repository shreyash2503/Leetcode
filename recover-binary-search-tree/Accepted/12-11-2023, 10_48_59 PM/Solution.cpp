// https://leetcode.com/problems/recover-binary-search-tree

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


    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        if(prev && prev->val > root->val){
            cout << "1" << endl;
            if(!first) first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right);

    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        
    }
};