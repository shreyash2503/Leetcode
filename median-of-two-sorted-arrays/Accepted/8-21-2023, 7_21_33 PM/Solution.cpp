// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int isEven = total % 2 == 0;

        vector<int> ans;
        int p1 = 0;
        int p2 = 0;
        while (p1 + p2 <= total / 2 && p1 < m && p2 < n) {
            if (nums1[p1] < nums2[p2]) {
                ans.push_back(nums1[p1]);
                p1++;
            } else {
                ans.push_back(nums2[p2]);
                p2++;
            }
        }

        // Append remaining elements from nums1 or nums2
        while (p1 < m) {
            ans.push_back(nums1[p1]);
            p1++;
        }
        while (p2 < n) {
            ans.push_back(nums2[p2]);
            p2++;
        }

        if (isEven) {
            return (ans[total / 2 - 1] + ans[total / 2]) / 2.0;
        } else {
            return ans[total / 2];
        }
    }
};
