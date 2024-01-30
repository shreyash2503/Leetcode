// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> weights(n, INT_MAX);

        weights[src] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        pq.push({0, src, 0});

        unordered_map<int, vector<pair<int, int>>> map;

        for(auto edge : flights){
            map[edge[0]].push_back({edge[1], edge[2]});
        }

        while(!pq.empty()){
            auto front = pq.top(); pq.pop();
            int node = get<1>(front);
            int weight = get<0>(front);
            int step = get<2>(front); 
            if(step > k) continue;

            for(auto neighbour : map[node]){
                auto acq = neighbour.first;
                auto cost = neighbour.second;
                auto currCost = weight + cost;
                if(currCost < weights[acq] && step <= k){
                    weights[acq] = currCost;
                    pq.push({currCost, acq, step + 1});
                }


            }
        }

        if(weights[dst] == INT_MAX) return -1;
        return weights[dst];
        
    }
};