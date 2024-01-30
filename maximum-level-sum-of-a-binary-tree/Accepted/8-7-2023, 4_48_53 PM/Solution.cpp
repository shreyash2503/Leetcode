// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    int helper(TreeNode* root){
        vector<pair<int, int>> v;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp && temp->left) q.push(temp->left);
                if(temp && temp->right) q.push(temp->right);
                sum += temp->val;
            }
            v.push_back(make_pair(sum, level));
            level++;
        }
        int max = INT_MIN;
        int l = -1;
        for(const auto& p : v){
            if(p.first > max){
                max = p.first;
                l = p.second;
            }
        }
        return l;
    }
    int maxLevelSum(TreeNode* root) {
        return helper(root);
        
    }
};