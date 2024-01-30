// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

class Solution {
public:
    bool helper(string word, vector<int> a){
        vector<int> b(26, 0);
        for(size_t i{};i<word.size();i++){
            b[word[i] - 'a']++;
        }
        for(size_t i{};i<26;i++){
            if(b[i] > a[i]){
                return false;
            }
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        vector<int> a(26, 0);
        for(auto c : chars){
            a[c - 'a']++;
        }
        unsigned int sum {};
        for(size_t i{};i<words.size();i++){
            if(helper(words[i], a)){
                sum += words[i].size();
            }
        }
        return sum;

        
        
    }
};