// https://leetcode.com/problems/find-mode-in-binary-search-tree

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
    vector<int> ans;
    int val = INT_MIN;
    int freq = 0;
    int maxFreq = INT_MIN;


    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }

        if(root->left){
            inorder(root->left);
        }
        if(val == root->val){
            freq ++;
        } else {
            val = root->val;
            freq = 1;
        } 
        if(freq == maxFreq){
            ans.push_back(val);
        }
        if(freq > maxFreq){
            maxFreq = freq;
            ans = {val};
        }

        inorder(root->right);


    }


    
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
        
    }
};