// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = INT_MIN;
        for(const auto& i : candies){
            if(i > max){
                max = i;
            }
        }
        cout << max;
        vector<bool> v;
        for(const auto& i : candies){
            if(i + extraCandies >= max){
                v.push_back(true);
            } else {
                v.push_back(false);
            }

        }
        return v;
        
    }
};