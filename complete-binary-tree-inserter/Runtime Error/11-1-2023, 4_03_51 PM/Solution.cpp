// https://leetcode.com/problems/complete-binary-tree-inserter

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
class CBTInserter {
public:
    vector<TreeNode*> v;
    TreeNode* root;
    int size = 0;
    CBTInserter(TreeNode* root) {
        this->v = vector<TreeNode*>(1001, NULL);
        this->root = root;
        traverse(root, 0);
    }


    void traverse(TreeNode* root, int start){
        if(root == NULL){
            return;
        }
        v[start] = root;
        this->size ++;
        traverse(root->left, 2 * start + 1);
        traverse(root->right, 2 * start + 2);

    }
    
    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        v[size] = node;
        int parent = (size - 1) / 2;
        this->size ++;
        TreeNode* _parent = v[parent];
        if(_parent){
            if(_parent->left == NULL){
                _parent->left = node;
            } else {
                _parent->right = node;
            }
            return _parent->val;
        }

        return -1;


        
    }
    
    TreeNode* get_root() {
        return this->root;
        
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */