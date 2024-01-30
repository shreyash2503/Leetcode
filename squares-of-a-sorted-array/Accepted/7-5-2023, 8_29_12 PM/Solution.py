// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums = [i * i for i in nums]
        nums.sort()
        return nums