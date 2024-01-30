// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:

   
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> v(n, vector<int>(n, -1)) ;

        for(auto edge : edges){
            v[edge[0]][edge[1]] = 1;
            v[edge[1]][edge[0]] = 1;
        }

        stack<int> s;
        vector<int> visited(edges.size(), 0);
        s.push(source);
        while(!s.empty()){
            int top = s.top();
            s.pop();
            visited[top] = 1;
            for(int j=0;j<v[top].size();j++){
                if(v[top][j] != -1 && v[top][destination] == 1){
                    return true;
                }
                if(v[top][j] != -1 && !visited[v[top][j]]){
                    s.push(v[top][j]);
                }
            }
            

        } 
        return false;
        
    }
};