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
        vector<int> number;
        int temp = length - 1;
        for(int i=0;i<length;i++){
            number.push_back(x % 10);
            x = x / 10;
            temp --;
        }
        cout<<length;
        int flag = length - 1;
        int b = 1;
        for(int i=0;i<length;i++){
            cout<<number[i];
        }
        cout<<endl;
        for(int i=0; i<length / 2;i++){
            if(number[flag] != number[i]){
                cout<<number[flag]<<" "<<number[i];
                b = 0;
            }
        }
        return b == 1 ? true : false;
        
    }
};