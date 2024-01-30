// https://leetcode.com/problems/special-positions-in-a-binary-matrix

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
       size_t row = mat.size();
       size_t col = mat[0].size();
       int ans {};

       for(size_t i{};i<row;i++){
           for(size_t j{};j<col;j++){
               if(mat[i][j] == 0){
                   continue;
               }

               bool good {true};
               // Checking for the row
               for(size_t r {};r<col;r++){
                   if(r != j && mat[i][r] == 1){
                       good = false;
                       break;
                   }
               }

               // Checking for the column
               for(size_t c {};c<row;c++){
                   if(c != i && mat[c][j] == 1){
                       good = false;
                       break;
                   }
               }

               if(good){
                   ans ++;
               }
           }
       } 


       return ans;
        
        
    }
};