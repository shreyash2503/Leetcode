// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        size_t size = s.size();

        int arr[26] {};
        for(size_t i{};i<size;i++){
            int index {s[i] - 'a'};
            arr[index]++;
        }
        for(size_t i{};i<size;i++){
            int index {t[i] - 'a'};
            arr[index]--;
        }

        for(size_t i{};i<26;i++){
            if(arr[i] != 0){
                return false;
            }
        } 
        return true;
      
        
    }
};