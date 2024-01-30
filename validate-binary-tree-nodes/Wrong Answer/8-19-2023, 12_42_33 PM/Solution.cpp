// https://leetcode.com/problems/validate-binary-tree-nodes

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parentCount(n, 0);
        for(int i=0;i<n;i++){
            if(leftChild[i] != -1){
                parentCount[leftChild[i]]++;
                if(parentCount[leftChild[i]] > 1){
                    return false;
                }
            }
            if(rightChild[i] != -1){
                parentCount[rightChild[i]]++;
                if(parentCount[rightChild[i]] > 1){
                    return false;
                }
            }
        }
        int root = 0;
        for(int i=0;i<n;i++){
            if(parentCount[i] == 0){
                root++;
            }
            if(root > 1){
                return false;
            }
        }
        return true;
    }
};