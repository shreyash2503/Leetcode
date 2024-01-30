// https://leetcode.com/problems/minimum-distance-between-bst-nodes

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
    void helper(TreeNode* root, vector<int> &min)
    {
        if(root == NULL) return;
        helper(root->left, min);
        min.push_back(root->val);
        helper(root->right, min);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> min;
        helper(root, min);
        return abs(min[0] - min[1]);
        
        
    }
};