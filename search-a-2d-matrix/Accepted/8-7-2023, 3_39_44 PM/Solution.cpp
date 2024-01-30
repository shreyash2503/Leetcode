// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool helper(vector<int> &arr, int target){
        int s = 0;
        int e = arr.size() - 1;
        while(s <= e){
            int mid = (s + e) / 2;
            if(arr[mid] > target){
                e = mid - 1;
            } else if(arr[mid] < target){
                s = mid + 1;
            } else if(arr[mid] == target){
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> arr;

        for(const auto &v : matrix){
            for(const auto &i : v){
                arr.push_back(i);
            }
        }
        return helper(arr, target);

        
    }
};