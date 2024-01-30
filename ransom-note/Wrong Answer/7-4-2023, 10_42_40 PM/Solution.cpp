// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        return magazine.find(ransomNote) != string::npos;
    }
};