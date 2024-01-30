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
        int flag = 1;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> v;
        v.push_back(vector<int>(1, root->val));
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            vector<int> _v;
            if(flag == 0){
                if(temp->left){
                    _v.push_back(temp->left->val);
                    if(temp->right){
                        q.push(temp->right);
                    }
                }
                if(temp->right){
                    _v.push_back(temp->right->val);
                    if(temp->left){
                        q.push(temp->left);
                    }
                }
                if(_v.size() != 0) {
                    v.push_back(_v);
                    flag = 1;
                    
                }
            } else {
                if(temp->right){
                    _v.push_back(temp->right->val);
                    if(temp->left){
                        q.push(temp->left);
                    }
                }
                if(temp->left){
                    _v.push_back(temp->left->val);
                    if(temp->right){
                        q.push(temp->right);
                    }
                }
                if(_v.size() != 0) {
                    v.push_back(_v);
                    flag = 0;
                }
            }
        }
        return v;

        
    }
};