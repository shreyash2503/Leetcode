// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        size_t size = words.size();
        size_t length {};
        for(auto str : words){
            length += str.size();
        }
        if(length % size != 0){
            return false;
        }

        vector<int> v(26, 0);
        for(auto str : words){
            for(auto c : str){
                v[c - 'a']++;
            }
        }

        for(auto i : v){
            if(i % size != 0){
                return false;
            }
        }
        return true;
        
    }
};