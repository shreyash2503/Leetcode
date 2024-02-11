class Solution {
public:
    int dfs(map<tuple<int, int, int>, int> &map, int r, int c1, int c2, vector<vector<int>>& grid){
        if(map.find({r, c1, c2}) != map.end()){
            return map[{r, c1, c2}];

        }
        if(c1 == c2 || min(c1, c2) < 0 || max(c1, c2) == grid[0].size()){
            return 0;
        }
        if(r == grid.size() - 1){
            return grid[r][c1] + grid[r][c2];
        }
        int res {};
        for(auto i : {-1, 0, 1}){
            for(auto j : {-1, 0, 1}){
                res = max(
                    res, 
                    dfs(map, r + 1, c1 + i, c2 + j, grid)

                );
            }
        }
        map[{r, c1, c2}] = res + grid[r][c1] + grid[r][c2];
        return map[{r, c1, c2}];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        map<tuple<int ,int, int>, int> map;
        return dfs(map, 0, 0, grid[0].size() - 1, grid);
        
    }
};
