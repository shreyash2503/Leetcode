// https://leetcode.com/problems/maximum-star-sum-of-a-graph

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if(edges.size() == 0 && vals.size() != 0){
            int max = INT_MIN;
            for(int i=0;i<vals.size(); i++){
                if(vals[i] > max){
                    max = vals[i];
                }
            }

            return max;
        }
        unordered_map<int, vector<int>> map;

        for(int i=0;i<edges.size();i++){
           map[edges[i][0]].push_back(vals[edges[i][1]]);
           map[edges[i][1]].push_back(vals[edges[i][0]]);
        }

        for(auto& pair : map){
            sort(pair.second.begin(), pair.second.end(), greater<int>());
        }

        int sum = INT_MIN;

        for(auto &pair : map){
            cout << pair.first << " ";
            for(auto i : pair.second){
                cout << i << " ";
            }
            cout << endl;
        }

        for(auto & pair : map){
            int temp = 0;
            if(pair.second.size() <= k){
                for(int i=0;i<k;i++){
                    temp += pair.second[i];

                }
                temp += vals[pair.first];
                if(temp > sum){
                    sum = temp;
                }
            }

        }

        return sum;
        
    }
};