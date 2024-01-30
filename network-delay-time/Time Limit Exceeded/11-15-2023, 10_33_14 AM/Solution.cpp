// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> map;
        vector<int> weights(n + 1, INT_MAX);
        for(auto edge : times){
            map[edge[0]].push_back({edge[1], edge[2]});
        }

        weights[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int cost;
        pq.push({0, k});
        while(!pq.empty()){
            int size = pq.size();

            auto front = pq.top(); pq.pop();
            auto node = front.second;
            auto weight = front.first;            
            for(auto& neighbour : map[node]){
                if(weight + neighbour.second < weights[neighbour.first]){
                    weights[neighbour.first] = weight + neighbour.second;

                }
                pq.push({weight + neighbour.second, neighbour.first});
            }
        }

        for(auto i : weights){
            cout << i << " ";
        }

        int ans = *max_element(weights.begin() + 1, weights.end());
        if(ans == INT_MAX){
            return -1;
        }

        return ans;
    }

};