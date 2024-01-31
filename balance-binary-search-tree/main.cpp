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
    void recursive(TreeNode* root, vector<TreeNode*> &v){
        if(root == NULL){
            return;
        }
        recursive(root->left, v);
        v.push_back(root);
        recursive(root->right, v);

        root->left = NULL;
        root->right = NULL;
    }
    TreeNode* constructTree(vector<TreeNode*> &v, int s, int e){
        if(s > e){
            return NULL;
        }
        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(v[mid]->val);
        root->left = constructTree(v, s, mid - 1);
        root->right = constructTree(v, mid + 1, e);
        
        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> v;
        recursive(root, v);
        size_t size = v.size();

        return constructTree(v, 0 , size - 1);
 
    }
};
