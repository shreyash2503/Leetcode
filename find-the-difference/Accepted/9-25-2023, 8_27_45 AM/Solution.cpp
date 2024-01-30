// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map;
        char ans;
        for(char c : t){
            map[c]++;
        }
        for(char c : s){

            map[c] --;
        }

        for(const auto& pair : map){
            if(pair.second > 0){
                ans = pair.first;

            }
        }

        return ans;

        
    }
};