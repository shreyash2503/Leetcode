// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
int helper(int n, int* arr){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 1;
    }
    if(arr[n] != -1){
        return arr[n];
    }
    int ans = helper(n - 1, arr) + helper(n - 2, arr);
    arr[n] = ans;
    return ans;
}
 int climbStairs(int n){
     int* arr = new int[n+1];
     for(int i=0;i<=n;i++){
         arr[i] = -1;
     }
     int x = helper(n , arr);
     return x;
 }
};