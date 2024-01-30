// https://leetcode.com/problems/same-tree

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

    bool helper(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }
        if(!p && q){
            return false;
        }
        if(p && !q){
            return false;
        }
        if(p->val != q->val){
            return false;
        }

        bool l = helper(p->left, q->left);
        bool r = helper(p->right, q->right);
        if(l && r){
            return true;
        }
        return false;


    }
    bool isSameTree(TreeNode* p, TreeNode* q) {

        return helper(p, q);
        
    }
};