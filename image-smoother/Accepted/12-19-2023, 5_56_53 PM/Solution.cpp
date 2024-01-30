// https://leetcode.com/problems/image-smoother

class Solution {
public:
    vector<pair<int, int>> neighbours(int row, int col){
        vector<pair<int, int>> v;
        v.push_back({row - 1, col});
        v.push_back({row + 1, col});
        v.push_back({row, col + 1});
        v.push_back({row, col - 1});
        v.push_back({row - 1, col - 1});
        v.push_back({row + 1, col + 1});
        v.push_back({row - 1, col + 1});
        v.push_back({row + 1, col - 1});
        return v;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        size_t row = img.size();
        size_t col = img[0].size();
        vector<vector<int>> blur(row, vector<int>(col, 0));
        for(size_t i{};i<row;i++){
            for(size_t j{};j<col;j++){
               auto v = neighbours(i, j); 
               int sum {img[i][j]};
               int count {1};
               for(size_t k{};k<v.size();k++){
                  auto& [x, y] = v[k]; 
                  if(x < row && y < col && x >= 0 && y >= 0){
                      sum += img[x][y];
                      count ++;
                  }
               }
                blur[i][j] = sum / count;
            }
        }

        
        return blur;
        
    }
};