// https://leetcode.com/problems/binary-tree-right-side-view

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
    void helper(TreeNode* root, vector<int>& arr){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp && temp->right){
                q.push(temp->right);
            } else if(temp && temp->left){
                q.push(temp->left);
            }
            if(temp){
                arr.push_back(temp->val);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;
        helper(root, arr);
        return arr;

        
    }
};