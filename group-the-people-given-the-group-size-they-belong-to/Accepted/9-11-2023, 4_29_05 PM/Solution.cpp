// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> map;

        vector<vector<int>> result;
        for(int i=0;i<groupSizes.size();i++){
            int size = groupSizes[i];
            map[size].push_back(i);
            if(map[size].size() == size){
                result.push_back(map[size]);
                map[size].clear();
            }
        }

        return result;
        
    }
};