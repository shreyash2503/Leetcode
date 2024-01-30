// https://leetcode.com/problems/design-graph-with-shortest-path-calculator

class Graph {
public:
    vector<vector<pair<int, int>>> adjList;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        // this->adjList = vector<vector<pair<int, int>>>(n);
        adjList.resize(n);
        this->n = n;
        
        for(auto &edge : edges){
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back({edge[1], edge[2]});
        
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> weight(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        weight[node1] = 0;
        pq.push({node1, 0});

        while(!pq.empty()){
            int currNode = pq.top()[0];
            int currCost = pq.top()[1];
            pq.pop();

            if(currCost > weight[currNode]){
                continue;
            }
            if(currNode == node2){
                return currCost;
            }
            for(auto& edge : adjList[currNode]){
                int neighbour = edge.first;
                int cost = edge.second;
                if(currCost + cost < weight[neighbour]){
                    weight[neighbour] = currCost + cost;
                    pq.push({neighbour, currCost + cost});
                }
            }
        }


        return -1;

        
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */