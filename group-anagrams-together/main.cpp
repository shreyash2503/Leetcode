class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(auto str : strs){
            string x = str;
            sort(x.begin(), x.end());
            map[x].push_back(str);
        }

        vector<vector<string>> v;
        for(auto [first, second] : map){
            v.push_back(second);
        }

        return v;
        
    }
};
