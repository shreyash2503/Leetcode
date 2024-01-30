// https://leetcode.com/problems/n-ary-tree-level-order-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};

        queue<Node*> q;
        Node* temp = root;
        vector<vector<int>> p;
        q.push(temp);
        vector<int> v;
        p.push_back({temp->val});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto front = q.front();
                q.pop();
                for(int j=0;j<front->children.size();j++){
                    v.push_back(front->children[j]->val);
                    q.push(front->children[j]);
                }
            }
            if(v.size() != 0){
                p.push_back(v);
                v.clear();
            }

        }

        return p;
        
    }
};