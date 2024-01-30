// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) {
            vector<vector<int>> v;
            return v;
        };
       
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()){
            vector<int>_v(q.size());
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                int idx = flag == 0 ? i : size - 1 - i;
                _v[idx] = temp->val;
            }
            v.push_back(_v);
            flag = 1 - flag;

        }
        return v;
    }
};