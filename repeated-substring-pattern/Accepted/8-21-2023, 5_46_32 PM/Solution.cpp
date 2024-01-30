// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s + s;
        if(temp.substr(1, temp.size() - 2).find(s) != -1) return true;
        return false;


        
    }
};