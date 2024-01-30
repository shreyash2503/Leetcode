// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {

        size_t size {arr.size()};
        size_t size_25 = size / 4;

        int curr {arr[0]};
        size_t count {1};

        for(size_t i=1;i<size;i++){
            if(arr[i] == curr){
                count++;
            } 
            if(count > size_25){
                break;
            }
            if(arr[i] != curr){
                curr = arr[i];
                count = 1;
            }

        }

        return curr;


        
    }
};