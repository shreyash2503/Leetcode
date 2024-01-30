// https://leetcode.com/problems/validate-binary-tree-nodes

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        queue<int> q;
        vector<int> e;
        q.push(0);
        int count = 0;

        while(!q.empty()){
            int ele = q.front();
            q.pop();
            if(find(e.begin(), e.end(), ele) != e.end()){
                return false;
            }
           if(leftChild[ele] != -1){
               if(find(e.begin(), e.end(), leftChild[ele]) != e.end()){
                   return false;
               } else {
                   q.push(leftChild[ele]);
               }
           }
           if(rightChild[ele] != -1){
               if(find(e.begin(), e.end(), rightChild[ele]) != e.end()){
                   return false;
               } else {
                   q.push(rightChild[ele]);
               }
           }
           e.push_back(ele);
           count ++;
        }
        if(count != leftChild.size()){
            return false;
        }
        
        
        return true;
    }
};