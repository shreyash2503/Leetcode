// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    bool DFS(int source, int destination, vector<vector<int>>v, vector<int> visited){

        visited[source] = 1;
        if(source == destination){
            return true;
        }

        for(int i=0;i<v[source].size();i++){
            if(v[source][i] != -1 && !visited[i]){
                if(DFS(i, destination, v, visited)){
                    return true;

                }
            }
        }

        return false;
    }

   
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n, 0);

        vector<vector<int>> v(n, vector<int>(n, -1));

        for(auto edge : edges){
            v[edge[0]][edge[1]] = 1;
            v[edge[1]][edge[0]] = 1;
        }

        return DFS(source, destination, v, visited);
      
    }
};