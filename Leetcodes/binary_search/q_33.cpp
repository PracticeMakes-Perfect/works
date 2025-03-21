/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:

Input: nums = [1], target = 0
Output: -1

 

Constraints:

    1 <= nums.length <= 5000
    -10^4 <= nums[i] <= 10^4
    All values of nums are unique.
    nums is an ascending array that is possibly rotated.
    -10^4 <= target <= 10^4


*/

class Solution {
private:
    int by_one_binary_search(vector<int>& nums, int& target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;

            } else if (nums[mid] >= nums[left]) {

                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }

            } else {
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                    
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
    int binary_search(vector<int>& nums, int& target, int left, int right) {

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] > target) {
                right = mid - 1;
                
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
    int by_two_binary_search(vector<int>& nums, int& target) {
        int n = nums.size();
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int left = 0;
        int right = n - 1;
        //not rotate
        if (nums[0] < nums[n - 1]) {
            int i = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();

            if (i < 0 || i == n) {
                return -1;
            }

            return nums[i] == target ? i : -1;
        }

        //find rotate position
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        int pos = binary_search(nums, target, 0, left);
        if (pos != -1) {
            return pos;
        }

        return binary_search(nums, target, left, n - 1);
    }
public:
    int search(vector<int>& nums, int target) {
        //return by_two_binary_search(nums, target);

        return by_one_binary_search(nums, target);
    }
};