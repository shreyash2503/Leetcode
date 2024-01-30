// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int length = 0;
        int num = x;
        while(num > 0){
            num = num / 10;
            length ++;
        }
        int number[length];
        int temp = length - 1;
        for(int i=0;i<length;i++){
            number[temp] = x % 10;
            x = x / 10;
            temp --;
        }
        int flag = length - 1;
        int b = 1;
        for(int i=0; i<length / 2;i++){
            if(number[flag] != number[i]){
                b = 0;
            }
        }
        return b == 1 ? true : false;
        
    }
};