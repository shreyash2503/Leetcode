// https://leetcode.com/problems/buy-two-chocolates

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1, min2;
        min1 = prices.at(0);
        min2 = prices.at(1);
         for (int i = 2; i < prices.size(); i++){
            if (prices.at(i) < min1){
                if (min1 < min2){
                    min2 = min1;
                }
                min1 = prices.at(i);
                
            }
            else if (prices.at(i) < min2){
                min2 = prices.at(i);
            }
         }
         if (min1 + min2 > money){
            return money;
         }
         else{
             return (money - (min1 + min2));
         }
    }
};