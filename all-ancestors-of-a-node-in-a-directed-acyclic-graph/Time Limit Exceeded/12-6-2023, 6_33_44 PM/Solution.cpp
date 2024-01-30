// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph

class Solution {
public:
    vector<int> bfs(int vertex, unordered_map<int, vector<int>> map, int n){
        queue<int> q;
        q.push(vertex);
        vector<int> ans;
        vector<int> visited(n, -1);
        while(!q.empty()){
            auto front = q.front(); q.pop();
            for(auto temp : map[front]){
                if(visited[temp] == -1){
                    visited[temp] = 0;
                    q.push(temp);
                    ans.push_back(temp);
                }
            }

        }

        return ans;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> ans(n);

        vector<vector<int>> _ans(n);
        unordered_map<int, vector<int>> map;

        for(auto v : edges){
            map[v[0]].push_back(v[1]);
        }

        for(int i=0;i<n;i++){
            vector<int> temp = bfs(i, map, n);
            ans[i] = temp;

        }
        for(auto v : ans){
            for(auto i : v){
                cout << i << " ";
            }
            cout << endl;
        }



        cout << "ans size is ::" << ans.size() << endl;
       for(int i=0;i<ans.size();i++){
           for(auto j : ans[i]){
               _ans[j].push_back(i);
           }
       }

    
        return _ans;

        
    }
};