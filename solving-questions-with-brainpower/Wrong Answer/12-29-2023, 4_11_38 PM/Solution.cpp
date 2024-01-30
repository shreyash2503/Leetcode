// https://leetcode.com/problems/solving-questions-with-brainpower

class Solution {
public:
    // long long helper(int index, vector<long long> &dp, vector<vector<int>> &questions){
    //     if(index >= questions.size()){
    //         return 0;
    //     }
    //     if(dp[index] != -1){
    //         return dp[index];
    //     }

    //     // Decided not to solve the question
    //     long long ans1 = helper(index + 1, dp, questions);

    //     //Decided to solve the question
    //     long long ans2 = questions[index][0] + helper(questions[index][1] + index + 1, dp, questions);
    //     dp[index] = max(ans1, ans2);
    //     return dp[index];



    // }
    long long mostPoints(vector<vector<int>>& questions) {
        size_t size = questions.size();
        vector<long long> dp(size, -1);
        // long long ans = helper(0, dp, questions);
        dp[questions.size() - 1] = questions[size - 1][0];

        for(int i=size-2;i>=0;i--){
            long long ans1 = dp[i + 1];
            int index = i + questions[i][1] + 1;
            long long ans2 = INT_MIN;
            if(index < size){
                ans2 = dp[index] + questions[i][0];
            }
            dp[i] = max(ans1, ans2);

        }

        return dp[0];
        
    }
};