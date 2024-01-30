// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        int m = word1.size() > word2.size() ? word2.size() : word1.size();
        int flag1 = 1;
        int flag2 = 0;
        string temp = "";
        while(i < m || j < m){
            if(flag1 == 1){
                temp += word1[i];
                flag1 = 0;
                flag2 = 1;
                i++;
                continue;

            }
            if(flag2 == 1){
                temp += word2[j];
                flag1 = 1;
                flag2 = 0;
                j++;
                continue;
            }

        }
        while(i < word1.size()){
            temp += word1[i];
            i++;
        }
        while(j < word2.size()){
            temp += word2[j];
            j++;
        }
        return temp;
        
    }
};