// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        queue<Node*> q2;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(!q2.empty()){
                if(q2.size() > 1){
                    Node* temp = q2.front();
                    q2.pop();
                    temp->next = q2.front();
                } else {
                    Node* temp = q2.front();
                    q2.pop();
                    temp->next = NULL;
                }
            }
            for(int i=0;i<size;i++){
                Node* temp = q.front();
                q.pop();
                if(temp && temp->left){
                    q.push(temp->left);
                    q2.push(temp->left);

                }
                if(temp && temp->right){
                    q.push(temp->right);
                    q2.push(temp->right);
                }
            }

        }
        return root;
    }
};