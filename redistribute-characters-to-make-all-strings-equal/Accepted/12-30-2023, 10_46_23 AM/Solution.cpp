// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

class Solution {
public:
    bool makeEqual(vector<string>& words) {
       unordered_map<char, int> map;
       size_t size = words.size();
       for(auto str : words){
           for(auto c : str){
               map[c]++;
           }
       } 

       for(const auto&[first, second] : map){
           if(second % size != 0){
               return false;
           }
       }
       return true;
    }
};