// https://leetcode.com/problems/largest-number

class Solution {
    public String largestNumber(int[] nums) {
        Integer[] nums1 = new Integer[nums.length];
        for(int i=0;i<nums.length;i++){
            nums1[i] = nums[i];
        }
        Arrays.sort(nums1, (a, b) -> {
            String str1 = String.valueOf(a) + String.valueOf(b);
            String str2 = String.valueOf(b) + String.valueOf(a);
            return str2.compareTo(str1);
        });
        if(nums1[0] == 0){
            return "0";
        }
       String ans = "";
       for(int i=0;i<nums.length;i++){
           ans += String.valueOf(nums1[i]);
       }
       return ans;
        
    }
}