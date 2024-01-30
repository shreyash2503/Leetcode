// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    void helper(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right, v);
        
        
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        helper(root, v);
        int i = 0;
        int j = v.size() - 1;
        while(i <= j){
            int sum = v[i] + v[j];
            if(sum == k){
                return true;
            } else if(sum > k){
                j--;
            } else {
                i++;
            }
        }
        return false;
        
    }
};