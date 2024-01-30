// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        vector<char> v;
        for(int i=0;i<n;i++){
            if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u'){
                v.push_back(s[i]);
            }
        }
        int j = v.size() - 1;

        for(int i=0;i<n;i++){
             if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u'){
                s[i] = v[j];
                j--;
            }
        }
        return s;
        
    }
};