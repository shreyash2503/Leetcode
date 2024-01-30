// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<double>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<double> v;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp && temp->left){
                    q.push(temp->left);
                }
                if(temp && temp->right){
                    q.push(temp->right);
                }
                if(temp){
                    v.push_back(temp->val);
                }
            }
            ans.push_back(v);
        }
        vector<double> p;
        for(const auto& v : ans){
            double total = 0;
            int size = v.size();
            for(const auto& i : v){
                total += i;

            }
            p.push_back(total / size);
            

        }
        return p;
        
    }
};