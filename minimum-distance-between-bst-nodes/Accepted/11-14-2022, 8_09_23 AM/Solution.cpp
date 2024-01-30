// https://leetcode.com/problems/minimum-distance-between-bst-nodes

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
    void helper(TreeNode* root, vector<int> &min)
    {
        if(root == NULL) return;
        helper(root->left, min);
        min.push_back(root->val);
        helper(root->right, min);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> min;
        helper(root, min);
        int min1 = INT_MAX;
        for(int i=0;i<min.size();i++)
        {
            for(int j=0;j<min.size();j++)
            {
                if(i != j)
                {
                if(min1 > abs(min[i] - min[j]))
                {
                    min1 = abs(min[i] - min[j]);
                }

                }
                
            }
        }
        return min1;
        
        
    }
};