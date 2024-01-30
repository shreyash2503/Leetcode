// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int minDistance(string a, string b) {
        int m = a.size();
        int n = b.size();
        if(m == 0){
            return n;
        }
        if(n == 0){
            return m;
        }
        if(m == 1 && n == 1 && a == b){
            return 0;
        }
        if(m == 1 && n == 1 && a != b){
            return 1;
        }
        int dp[m + 1][n + 1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                } else if(a[i - 1] == b[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                } else{
                    dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
                }
            }
        }
        return dp[m][n];
        
    }
};