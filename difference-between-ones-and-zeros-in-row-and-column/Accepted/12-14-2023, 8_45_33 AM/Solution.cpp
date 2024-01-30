// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        size_t row = grid.size();
        size_t col = grid[0].size();
        vector<vector<int>> diff(row, vector<int>(col, 0));

        vector<int> onesRow(row, 0);
        vector<int> onesCol(col, 0);
        vector<int> zerosRow(row, 0);
        vector<int> zerosCol(col, 0);

        for(size_t i{};i<row;i++){

            int sum {};
            for(size_t j{};j<col;j++){
                sum += grid[i][j];
            }
            onesRow[i] = sum;
        }


        for(size_t i{};i<col;i++){
            int sum{};
            for(size_t j{};j<row;j++){
                sum += grid[j][i];
            }
            onesCol[i] = sum;
        }

        for(size_t i{};i<row;i++){
            zerosRow[i] = row - onesRow[i];
        }
        
        for(size_t i{};i<col;i++){
            zerosCol[i] = col - onesCol[i];
        }

        for(size_t i {};i<row;i++){
            for(size_t j{};j<col;j++){
                diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];

            }
        }

        return diff;



        
    }
};