// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int columnNumber) {
        char capital[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int num = columnNumber;
        if(columnNumber <= 26){
            return string(1, capital[columnNumber]);
        }
        string s = "";
        while(num > 0){
         int x = num % 26;
         if(x == 0 && num == 1){
            s = s + 'Z';
         }
         s = s + capital[x];
         num = num / 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};