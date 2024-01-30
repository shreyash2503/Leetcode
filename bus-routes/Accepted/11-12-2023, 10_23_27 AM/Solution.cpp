// https://leetcode.com/problems/bus-routes

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0;
        }
        unordered_map<int, vector<int>> adjList;

        for(int i=0;i<routes.size();i++){
            for(auto stop : routes[i]){
                adjList[stop].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> vis;

        for(auto route : adjList[source]){
            q.push(route);
            vis.insert(route);
        }

        int busCount = 1;

        while(q.size()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int front = q.front(); q.pop();

                for(auto stop : routes[front]){
                    if(stop == target){
                        return busCount;
                    }

                    for(auto route : adjList[stop]){
                        if(!vis.count(route)){
                            q.push(route);
                            vis.insert(route);
                        }
                    }
                }
            }
            busCount ++;
        }
        
        return -1;
    }
};