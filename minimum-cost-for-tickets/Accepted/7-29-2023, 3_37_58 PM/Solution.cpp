// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:

    int helper(int n, vector<int>&days, vector<int> &costs, int index, vector<int> &dp){
        if(index >= n){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }
        int _1 = costs[0] + helper(n, days, costs, index + 1, dp);
        int i;
        for(i=index;i<n && days[i] < days[index] + 7; i++);
        int _7 = costs[1] + helper(n, days, costs, i, dp);
        for(i=index;i<n && days[i] < days[index] + 30; i++);
        int _30 = costs[2] + helper(n, days, costs, i, dp);
        dp[index] = min(min(_1, _7), _30);
        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1);
        return helper(n, days, costs, 0, dp);

        
    }
};