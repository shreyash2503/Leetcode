// https://leetcode.com/problems/calculate-money-in-leetcode-bank

class Solution {
public:
    int totalMoney(int n) {
        int number = 1;
        int sum = 0;
        int currNumber = 1;
        for(int i=1;i<=n;i++){
            cout << currNumber << endl;
            if(i % 7 == 0){
                sum += currNumber;
                currNumber = number + 1;
                number = number + 1;
            } else {
                sum += currNumber;
                currNumber += 1;
            }

        }

        return sum;
        
    }
};