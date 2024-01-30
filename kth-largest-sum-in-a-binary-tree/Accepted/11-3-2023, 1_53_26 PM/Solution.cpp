// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> v;

        queue<TreeNode*> q;

        TreeNode* temp = root;

        q.push(temp);

        while(!q.empty()){
            long long sum = 0;
            int size = q.size();
            for(int i=0;i<size;i++){
                auto front = q.front(); q.pop();
                sum += front->val;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }

            v.push_back(sum);
        }

        sort(v.rbegin(), v.rend());
        if(v.size()  < k){
            return -1;
        }
        return v[k - 1];
        
    }
};