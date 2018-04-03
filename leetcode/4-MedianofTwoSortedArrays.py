# -*- coding: utf-8
# !/usr/bin/env python


class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        position1, position2 = len(nums1)/2, len(nums2)/2
        mid1, mid2 = nums1[position1], nums2[position2]

        if mid1 == mid2:
            return mid1
        elif mid1 > mid2:
            if position2 == 0:
                return
            return self.findMedianSortedArrays(nums1[position1:], nums2[:position2])
        else:
            return self.findMedianSortedArrays(nums1[:position1], nums2[position2:])

if __name__ == '__main__':
    solution = Solution()

    num1 = [1, 3]
    num2 = [2]
    result = solution.findMedianSortedArrays(num1, num2)
    print result