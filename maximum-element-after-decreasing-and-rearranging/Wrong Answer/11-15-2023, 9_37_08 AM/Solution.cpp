// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i] - arr[i - 1]) > 1){
                arr[i] = arr[i - 1] + 1;
            }

        }
        
        return *max_element(arr.begin(), arr.end());
    }

};