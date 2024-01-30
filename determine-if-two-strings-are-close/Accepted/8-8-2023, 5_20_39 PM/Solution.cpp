// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return false;
        }
        string m, n;
        unordered_map <char, int> map1;
        unordered_map<int, string> w1;



        unordered_map <char, int> map2;
        unordered_map <int, string> w2;

        for(const auto& i : word1){
            if(map1.find(i) == map1.end()){
                map1[i] = 1;
            } else {
                map1[i] ++;
            }
        }
        for(auto it : map1){
            w1[it.second].push_back(it.first);
        }



        for(const auto& i : word2){
            if(map2.find(i) == map2.end()){
                map2[i] = 1;
            } else {
                map2[i] ++;
            }
        }

        for(auto it : map2){
            w2[it.second].push_back(it.first);
        }
        if(w1.size() != w2.size()) return false;

        for(auto it : map1){
            m += it.first;
        }
        for(auto it : map2){
            n += it.first;
        }
        sort(m.begin(), m.end());
        sort(n.begin(), n.end());

        if(m != n) return false;

        for(auto it : w1){
            if(w2[it.first].size() != it.second.size()) return false;
        }
        return true;


        
    }
};