// https://leetcode.com/problems/longest-univalue-path

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
    int helper(TreeNode* root, int prev){
        if(root == NULL){
            return 0;
        }
        int l = helper(root->left, root->val);
        int r = helper(root->right, root->val);
        if(prev == root->val){
            return 1 + l + r;
        }

        return max(l, r);

    }
    int longestUnivaluePath(TreeNode* root) {
        int prev = root->val;
        int ans = helper(root, prev) - 1;
        cout << ans;

        return ans;

        
    }
};