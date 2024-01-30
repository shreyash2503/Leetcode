// https://leetcode.com/problems/the-k-strongest-values-in-an-array

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = arr.size() - 1;
        int med = arr[(arr.size() - 1) / 2];

        while(--k >= 0){
            if(abs(arr[i] - med) > arr[j] - med)
                ++i;
            else:
                --j;

        }
        arr.erase(begin(arr) + i, begin(arr) + j + 1)
        return arr;

        
    }
};