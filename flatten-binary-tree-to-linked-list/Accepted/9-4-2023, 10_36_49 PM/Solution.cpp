// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    void helper(TreeNode* root, vector<TreeNode*> &v){
        if(root == NULL){
            return;
        }
        v.push_back(root);
        helper(root->left, v);
        helper(root->right, v);
    }

    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        vector<TreeNode*> v;
        helper(root, v);
        TreeNode* r = v[0];
        for(int i=1;i<v.size();i++){
            r->left = NULL;
            r->right = NULL;
            r->right = v[i];
            r = r->right;
        }
        
    }
};