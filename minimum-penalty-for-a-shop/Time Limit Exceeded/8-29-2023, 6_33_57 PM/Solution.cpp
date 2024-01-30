// https://leetcode.com/problems/minimum-penalty-for-a-shop

class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        int min = INT_MAX;
        int position = -1;
        for(int i=0;i<customers.size();i++){
            if(customers[i] == 'Y'){
                penalty ++;
            }
        }
        min = penalty;
        position = 0;
        penalty = 0;
        for(int i=0;i<customers.size();i++){
            for(int j=0;j<=i;j++){
                if(customers[j] == 'N'){
                    penalty++;
                }
            }
            for(int j=i+1;j<customers.size();j++){
                if(customers[j] == 'Y'){
                    penalty++;
                }

            }
            if(min > penalty){
                min = penalty;
                position = i + 1;
            }
            penalty = 0;
        }
        return position;
    }
        
};