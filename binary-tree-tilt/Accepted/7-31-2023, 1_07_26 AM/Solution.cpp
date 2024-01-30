// https://leetcode.com/problems/binary-tree-tilt

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
    int helper(TreeNode* root, vector<int>& v){
        if(root == NULL){
            return 0;
        }
        int left = helper(root->left, v);
        int right = helper(root->right, v);
        v.push_back(abs(left - right));
        return root->val + left + right;
        

    }
    int findTilt(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        int sum = 0;
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            sum += v[i];
        }

        return sum;
        
    }
};