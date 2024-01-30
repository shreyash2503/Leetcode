// https://leetcode.com/problems/maximum-depth-of-n-ary-tree

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
    int helper(Node* root){
        if(root->children.size() == 0){
            return 1;
        }
        int max = INT_MIN;
        for(int i=0;i<root->children.size();i++){
            int temp = helper(root->children[i]) + 1;
            if(temp > max){
                max = temp;
            }
        }
        return max;
       
    }
    int maxDepth(Node* root) {
        return helper(root);
        
    }
};