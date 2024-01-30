// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int search = arr[0];
        int start = 0;
        int end = arr.size() - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]){
                start = mid;
            } else if (arr[mid - 1] > arr[mid] > arr[mid + 1]) {
                end = mid;
            } else {
                return mid;
            }
        }

        return -1;
        
    }
};