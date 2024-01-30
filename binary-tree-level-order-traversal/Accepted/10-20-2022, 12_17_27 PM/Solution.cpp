// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // queue<TreeNode *> q;
        // vector<vector<int>> v;
        // if(root == NULL)
        // {
        //     return v;
        // }
        // vector<int> flag;
        // q.push(root);
        // q.push(NULL);
        // int i = 0;
        // while(!q.empty())
        // {
        //     TreeNode *temp = q.front();
        //     q.pop();
        //     if(temp == NULL)
        //     {
        //         v.push_back(flag);
        //         flag.clear();
        //         if(!q.empty())
        //         {
        //             q.push(NULL);
        //         }
        //     }
        //     else
        //     {
        //         flag.push_back(temp->val);
        //         if(temp->left)
        //         {
        //             q.push(temp->left);
        //         }
        //         if(temp->right)
        //         {
        //             q.push(temp->right);
        //         }
               
        //     }

        // }

        // return v;
        queue<TreeNode*> q;
        vector<vector<int>> v;
        if(root == NULL)
        {
            return v;
        }
        q.push(root);
        while(!q.empty())
        {
            vector<int> child;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *flag = q.front();
                q.pop();
                if(flag->left)
                {
                    q.push(flag->left);
                }
                if(flag->right)
                {
                    q.push(flag->right);
                }
                child.push_back(flag->val);
            }
            v.push_back(child);
        }

        return v;
        
    }
};