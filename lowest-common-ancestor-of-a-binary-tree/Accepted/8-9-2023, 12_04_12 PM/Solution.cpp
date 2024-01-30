// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* l = helper(root->left, p, q);
        TreeNode* r = helper(root->right, p, q);
        if(l && r){
            return root;
        }
        if(l){
            return l;
        }
        if(r){
            return r;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
        
    }
};