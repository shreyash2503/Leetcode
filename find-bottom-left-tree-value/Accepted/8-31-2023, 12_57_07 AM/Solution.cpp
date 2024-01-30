// https://leetcode.com/problems/find-bottom-left-tree-value

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
    void helper(TreeNode* root, int count, vector<pair<int,int>> &v){
        if(root == NULL){
            return;
        }
        if(root->right == NULL && root->left == NULL){
            auto p = make_pair(count, root->val);
            v.push_back(p);
            return;
        }
        helper(root->left, count + 1, v);
        helper(root->right, count + 1, v);
       
        

    }
    int findBottomLeftValue(TreeNode* root) {

        vector<pair<int,int>> v;
        int count = 0;
        helper(root, count, v);
        int max = INT_MIN;
        int pos = -1;
        for(const auto& p : v){
            if(p.first > max){
                max = p.first;
                pos = p.second;
            }
        }
        return pos;
        
        
    }
};