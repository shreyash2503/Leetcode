// https://leetcode.com/problems/search-in-a-binary-search-tree

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        TreeNode* temp1 = NULL;
        TreeNode* temp2 = NULL;
        if(root->val > val)
        {
            temp1 = searchBST(root->left, val);
        }
        if(root->val < val)
        {
            temp2 = searchBST(root->right, val);

        }
        if(root->val == val)
        {
            return root;
        }

       return temp1 == NULL ? temp2 : temp1;
        
    }
};