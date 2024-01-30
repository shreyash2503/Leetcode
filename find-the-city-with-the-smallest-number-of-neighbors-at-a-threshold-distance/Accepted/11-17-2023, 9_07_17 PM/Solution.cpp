// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

class Solution {
public:
    int helper(unordered_map<int, vector<pair<int, int>>> map, int n, int sv, int threshold){
        vector<int> weights(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, sv});

        weights[sv] = 0;
        vector<int> visited(n, 0);
        while(!pq.empty()){
            auto front = pq.top(); pq.pop();
            auto node = front.second;
            auto weight = front.first;
            if(visited[node] == 0){

                for(auto neighbour : map[node]){
                    auto acq = neighbour.first;
                    auto cost = neighbour.second;
                    auto currCost = cost + weight;
                    if(currCost < weights[acq] && currCost <= threshold) {
                        weights[acq] = currCost;
                        pq.push({currCost, acq});
                    }
                }
                visited[node] = 1;
            }

        }
        int sum = 0;
        cout << sv << endl;
        // for(auto i : weights){
        //     cout << i << " ";
        //     if(i != INT_MAX && i != sv) {
        //         sum++;
        //     }

        // }
        for(int i=0;i<weights.size();i++){
            cout << weights[i] << " "; 
            if(weights[i] != INT_MAX && i != sv){
                sum++;
            }
        }
        cout << endl;
        return sum;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        unordered_map<int, vector<pair<int, int>>> map;
        for(auto edge : edges){
            map[edge[0]].push_back(make_pair(edge[1], edge[2]));
            map[edge[1]].push_back(make_pair(edge[0], edge[2]));
        }

        int node;
        int sum = INT_MAX;
        for(int i=0;i<n;i++){
            int ans = helper(map, n, i, distanceThreshold);
            cout << ans;
            if(ans < sum){
                node = i;
                sum = ans;
                continue;
            }
            
            if(ans == sum && i > node){
                node = i;
                sum = ans;

            }
        }

        cout << node;
        return node;
        
    }
};