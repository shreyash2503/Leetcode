// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto pair : adjacentPairs){
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        int root = 0;
        for(auto const& pair : graph){
            if(pair.second.size() == 1){
                root = pair.first;
                break;
            }
        }
        vector<int> ans;
        dfs(root, INT_MAX, ans);
        return ans;


        
    }
    void dfs(int root, int prev, vector<int> &ans) {
        ans.push_back(root);
        for(auto neighbour : graph[root]){
            if(neighbour != prev){
                dfs(neighbour, root, ans);
            }
        }
    }
};