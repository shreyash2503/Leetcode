// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
    TreeNode* helper(vector<int>&nums, int s, int e)
    {
        if(s > e) return NULL;
        int middle = (s+e)/2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = helper(nums, s, middle-1);
        root->right = helper(nums, middle+1, e);
        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         return helper(nums, 0, nums.size()-1);

        
    }
};