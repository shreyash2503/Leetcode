// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    void helper(TreeNode* root, set<string> &v, string s){
        if(root == NULL){
            v.insert(s);
            return;
        }
        helper(root->left, v, s + to_string(root->val));
        helper(root->right, v, s + to_string(root->val));

    }
    int sumNumbers(TreeNode* root) {
       set<string> v; 
       helper(root, v, "");
        int sum = 0;
       for(auto i : v){
           cout << i << endl;
           int element = stoi(i);
           sum += element;
       }
       return sum;

    }
};