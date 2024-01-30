// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        queue <int> q;
        for(int i=0;i<graph.size();i++){
            q.push(i);
            if(color[i] >= 0) continue;
            color[i] = 0;

            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(auto neighbour : graph[front]){
                    if(color[neighbour] == color[front]) return false;
                    if(color[neighbour] >= 0) continue;
                    color[neighbour] = !color[front];
                    q.push(neighbour);
                }
            }
        }
        
    return true;
    }

};