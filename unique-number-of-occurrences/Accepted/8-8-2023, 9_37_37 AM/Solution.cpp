// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for(const auto& i : arr){
            if(map.find(i) == map.end()){
                map[i] = 1;
            } else {
                map[i] ++;
            }
        }
        vector<int> v;
        for(const auto& p : map){
            if(find(v.begin(), v.end(), p.second) == v.end()){
                v.push_back(p.second);
            } else {
                return false;
            }

        }
        return true;
        
    }
};