// https://leetcode.com/problems/find-eventual-safe-states

class Solution {
public:
    void solve(vector<int> &visited, vector<vector<int>>& graph, int i){
        visited[i] = 2;
        for(auto it : graph[i]){
            if(!visited[it]){
                solve(visited, graph, it);
            }
            if(visited[it] == 2) return;
        }
        visited[i] = 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), 0);
        vector<int> v;
        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                solve(visited, graph, i);
            }
        }

        for(int i=0;i<visited.size();i++){
            if(visited[i] == 1) v.push_back(i);
        }
        return v;


        
    }
};