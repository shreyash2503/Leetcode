// https://leetcode.com/problems/destination-city

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> map;
        for(auto &v : paths){
            map[v[0]] = v[1];
            if(map.find(v[1]) == map.end()){
                map[v[1]] = "-1";
            }
        }

        string s = "";
        for(auto &[first, second] : map){
            if(map[first] == "-1"){
                s = first;
                break;
            }
        }

        return s;
        
    }
};