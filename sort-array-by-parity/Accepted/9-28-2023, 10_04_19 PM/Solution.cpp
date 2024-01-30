// https://leetcode.com/problems/sort-array-by-parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

       sort(nums.begin(), nums.end(), [](auto &a, auto &b){
           if(a % 2 == 0 && b % 2 != 0) return true;
           return false;
       });

       return move(nums);



        
    }
};