// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

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
        //create a prev for each iteration 
        //prev of next will be set to current each time
       
        if(!root){
            return root;
        }
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            Node *prev = nullptr;
            while(count--){
                //get the current node
                Node *current = q.front();
                q.pop();

                //insert its left and right if required
                if(current -> left){
                    q.push(current -> left);
                }
                if(current -> right){
                    q.push(current -> right);
                }
                if(!prev){
                    prev = current;
                } else {
                    prev -> next = current;
                    prev = current;
                }
            }
        }
        return root;
    }
};