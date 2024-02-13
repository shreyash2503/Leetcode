class Solution {
public:
    bool checkPalindrome(string s){
        string t = s;
        reverse(s.begin(), s.end());

        if(t == s){
            return true;
        }
        return false;
    }
    string firstPalindrome(vector<string>& words) {
        size_t size = words.size();
        for(int i{};i<size;i++){
            if(checkPalindrome(words[i])){
                return words[i];
            }
        }

        return "";
        
    }
};
