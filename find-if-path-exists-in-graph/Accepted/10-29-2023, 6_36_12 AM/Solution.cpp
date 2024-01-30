// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    unordered_map<int,vector<int>> mp;
    unordered_set<int> travelled;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {    
        for(auto &e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        dfs(source);
        return travelled.find(destination) != travelled.end();
    }

    void dfs(int source){
        if(travelled.find(source) != travelled.end()) return;
        travelled.insert(source);
        for(auto &s : mp[source]) dfs(s);
    }
   
};