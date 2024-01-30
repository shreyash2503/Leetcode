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
    void helper(TreeNode* root, vector<int>& v){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            TreeNode* temp = q.front();
            q.pop();
            if(temp) v.push_back(temp->val);
            if(temp && temp->right) q.push(temp->right);
            if(temp && temp->left) q.push(temp->left);
            for(int i=1;i<size;i++){
                TreeNode* ele = q.front();
                q.pop();
                if(ele && ele->right) q.push(ele->right);
                if(ele && ele->left) q.push(ele->left);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;
        helper(root, arr);
        return arr;

        
    }
};