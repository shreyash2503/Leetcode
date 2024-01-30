// https://leetcode.com/problems/binary-tree-paths

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
    void helper(TreeNode* root, vector<string> &v, string &temp){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            v.push_back(temp + to_string(root->val));
            return;
        }
        temp += to_string(root->val) + "->";
        string str = temp;
        helper(root->left, v, temp);
        helper(root->right, v, str);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string temp = "";
        helper(root, v, temp);
        return v;
        
    }
};