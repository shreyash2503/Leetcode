// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size() == 0){
            return;
        }
       int end1 = m - 1;
       int end2 = n - 1;
       int temp = m + n - 1;
       
       if(nums1[0] == 0){
           nums1[0] = nums2[0];
           return;
       }
       while(end1 > 0 && end2 >= 0){
           if(end1 >= 0 && nums1[end1] > nums2[end2]){
               nums1[temp] = nums1[end1];
               end1 --;
               temp --;
           } else {
               nums1[temp] = nums2[end2];
               end2 --;
               temp --;
           }
       }

    }
};