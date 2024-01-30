// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree

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
    pair<int, int> getHeightAndSum(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }
        pair<int, int> l = getHeightAndSum(root->left);
        pair<int, int> r = getHeightAndSum(root->right);


        return {l.first + r.first + 1, l.second + r.second + root->val};
        
    }

    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        pair<int, int> ans = getHeightAndSum(root);
        if(ans.second / ans.first == root->val){
            return helper(root->left) + helper(root->right) + 1;
        }

        return helper(root->left) + helper(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        return helper(root);
    }
};