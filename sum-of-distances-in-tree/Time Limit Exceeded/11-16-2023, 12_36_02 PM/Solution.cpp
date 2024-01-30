// https://leetcode.com/problems/sum-of-distances-in-tree

class Solution {
public:
    int helper(unordered_map<int, vector<int>> map, int n, int sv){
        vector<int> weights(n, INT_MAX);
        vector<int> visited(n, 0);
        weights[sv] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({sv, 0});

        while(!pq.empty()){
            auto front = pq.top(); pq.pop();
            int node = front.first;
            int weight = front.second;

            if(visited[node] == 0){
                for(auto neighbour : map[node]){
                    int currCost = weight + 1;
                    if(currCost < weights[neighbour]){
                        weights[neighbour] = currCost;
                        pq.push({neighbour, currCost});
                    }
                }

                visited[node] = 1;

            }
        }
        int sum = 0;
        for(auto i : weights){
            sum += i;
        }


        return sum;

    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> map;

        for(auto edge : edges){
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(helper(map, n, i));
        }

        return ans;
        
    }
};