// https://leetcode.com/problems/distribute-candies

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(candyType[i]);
        }
        cout<<s.size();
        if(s.size() > n / 2){
            return (int) n / 2;
        } else {
            return s.size();
        }

        
    }
};