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
    CBTInserter(TreeNode* root) {
        this->root = root;
        traverse(root, 0);
    }


    void traverse(TreeNode* root, int start){
        if(root == NULL){
            return;
        }
        // v[start] = root;
        // this->size ++;
        // traverse(root->left, 2 * start + 1);
        // traverse(root->right, 2 * start + 2);

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto front = q.front(); q.pop();
            v.push_back(front);
            if(front->left){
                q.push(front->left);
            } 
            if(front->right){
                q.push(front->right);
            }

        }

    }
    
    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        v.push_back(node);
        int size = v.size() - 1;
        int parent = (size - 1) / 2;
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