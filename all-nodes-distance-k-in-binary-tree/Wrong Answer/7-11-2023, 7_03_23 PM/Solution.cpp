// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findHeight(TreeNode* root, int target, bool hash, int* height){
        if(root == NULL){
            return false;
        }
        if(root->val == target){
            return true;
        }
        if(findHeight(root->left, target, hash, height)){
            *height = *height + 1;
            return true;
        }
        if(findHeight(root->right, target, hash, height)){
            *height = *height + 1;
            return true;
        }
        return false;
    }
    void helper(TreeNode* root, vector<int> &ans, int k, int distance){
        if(root == NULL){
            return;
        }
        if(distance  == k){
            ans.push_back(root->val);
            return;
        }
        helper(root->left, ans, k, distance + 1);
        helper(root->right, ans, k, distance + 1);


    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0){
            vector<int> v;
            v.push_back(target->val);
            return v;
        }
        TreeNode* temp = root;
        vector<int> ans;
        int* height = new int;
        *height = 1;
        TreeNode* flag = target;
        bool hash1 = findHeight(temp->left, target->val, false, height);
        bool hash2 = findHeight(temp->right, target->val, false, height);
        cout<<hash1<<hash2<<endl;
        if(*height == k){
            ans.push_back(root->val);
        }
        if(hash1){
            if(*height > k){
                TreeNode* a = root;
                helper(flag, ans, k, 0);
                int diff = *height - k;
                cout<<"The height is ::"<<*height<<endl;
                helper(a->left, ans, diff, 1);

            } else {
                cout<<"Hey buddy";
                TreeNode* a = root;
                helper(flag, ans, k, 0);
                int diff = k - *height;
                cout<<a->val<<endl;
                cout<<diff<<endl;
                helper(a->right, ans, diff, 1);
                
            }
        } else {
            if(*height > k){
                TreeNode* a = root;
                helper(flag, ans, k, 0);
                int diff = *height - k;
                helper(a->right, ans, diff, 1);

            } else {
                TreeNode* a = root;
                helper(flag, ans, k, 0);
                int diff = k - *height;
                helper(a->left, ans, diff, 1);
                
            }

        }
        return ans;

        

        
    }
};