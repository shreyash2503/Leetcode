// https://leetcode.com/problems/find-the-difference-of-two-arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        vector<int> ans1;
        vector<int> ans2;
        
        for(int i=0;i<nums1.size();i++){
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            if(it == nums2.end()){
                ans1.push_back(nums1[i]);
            }
        }
        for(int i=0;i<nums2.size();i++){
            auto it = find(nums1.begin(), nums1.end(), nums2[i]);
            if(it == nums1.end()){
                ans2.push_back(nums2[i]);
            }
        }

        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};