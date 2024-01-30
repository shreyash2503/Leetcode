// https://leetcode.com/problems/maximum-binary-tree

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

    TreeNode* helper(vector<int> & nums, int s, int e){
        if(s >= e){
            return NULL;
        }
        int max_index = max_element(nums.begin() + s, nums.begin() + e) - nums.begin();
        cout << max_index << endl;
        TreeNode* node = new TreeNode(nums[max_index]); 
        if(max_index - 1 >= 0){
            node->left = helper(nums, s, max_index);
        } else {
            node->left = NULL;
        }
        if(max_index + 1 < e){
            node->right = helper(nums, max_index + 1, e);
        } else {
            node->right = NULL;
        }

        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size());
        
        
    }
};