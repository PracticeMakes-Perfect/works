/*
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.

Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.

 

Constraints:

    1 <= nums1.length, nums2.length <= 10^5
    1 <= nums1[i], nums2[j] <= 10^9
    Both nums1 and nums2 are sorted in non-decreasing order.


*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size()) {
            return getCommon(nums2, nums1);
        }

        //two pointer
        int p1 = 0;
        int p2 = 0;
        while (p1 < nums1.size() && p2 < nums2.size()) {

            if (nums1[p1] == nums2[p2]) {
                return nums1[p1];
            } else if (nums1[p1] > nums2[p2]) {
                ++p2;
            } else {
                ++p1;
            }
        }

        //binary search
        /*
        int N2 = nums2.size();
        int left = 0;
        int right = N2 - 1;
        for (int i = 0; i < nums1.size(); ++i) {
            left = 0;
            right = N2 - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (nums2[mid] == nums1[i]) {
                    return nums1[i];
                } else if (nums2[mid] > nums1[i]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        */

        return -1;
    }
};