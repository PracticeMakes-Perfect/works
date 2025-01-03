/*
Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

Return the positive integer k. If there is no such integer, return -1.

 

Example 1:

Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.

Example 2:

Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.

Example 3:

Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.

 

Constraints:

    1 <= nums.length <= 1000
    -1000 <= nums[i] <= 1000
    nums[i] != 0


*/

class Solution {
private:
    int byTwoPointers(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int N = nums.size();

        int right = N - 1;
        int left = 0;
        for (int i = 0; i < N; ++i) {
            if (-nums[left] == nums[right]) {
                return nums[right];

            } else if (-nums[left] > nums[right]) {
                 ++left;
            } else {
                --right;
            }
        }

        return -1;
    }
    int byBinarySearch(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        for (int i = N - 1; i > -1; --i) {

            if (-nums[i] > 0) {
                return -1;
            }

            int val = *std::lower_bound(nums.begin(), nums.end(), -nums[i]);

            if (val == -nums[i]) {
                return nums[i];
            }
        }

        return -1;
    }
public:
    int findMaxK(vector<int>& nums) {
        //return byBinarySearch(nums);
        return byTwoPointers(nums);
    }
};