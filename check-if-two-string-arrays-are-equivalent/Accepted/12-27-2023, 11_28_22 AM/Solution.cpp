// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s = "";
        string t = "";
        for(size_t i{};i<word1.size();i++){
            s += word1[i];
        }
        for(size_t j{};j<word2.size();j++){
            t += word2[j];
        }
        
        return s == t;
        
    }
};