// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    int helpe(TreeNode* root){
        TreeNode* temp = root;
        stack<TreeNode*> s;
        s.push(temp);
        int max = INT_MIN;
        int count = 0;
        while(!s.empty()){
            TreeNode* flag = s.top();
            s.pop();
            if(flag->val >= max){
                count++;
                max = flag->val;
            }
            if(flag->right){
                s.push(flag->right);
            }
            if(flag->left){
                s.push(flag->left);
            }
        }
        return count;
    }
    int helper(TreeNode* root, int max){
        if(root == NULL){
            return 0;
        };
        int count  = 0;
        if(root->val >= max){
            count++;
            max = root->val;
        }
        count += helper(root->left, max);
        count += helper(root->right, max);
        return count;


    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        int max = INT_MIN;
        return helper(root, max);
        
    }
};