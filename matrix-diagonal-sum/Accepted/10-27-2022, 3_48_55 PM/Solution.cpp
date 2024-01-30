// https://leetcode.com/problems/matrix-diagonal-sum

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0;i<mat.size();i++){
            for(int j =0;j<mat.size();j++){
                if(i == j)
                {
                    sum1 = sum1 + mat[i][j];
                }
                if(i+j == mat.size() - 1 && i != j)
                {
                    sum2 = sum2 + mat[i][j];
                }
            }
        }
        return sum1 + sum2;
        
    }
};