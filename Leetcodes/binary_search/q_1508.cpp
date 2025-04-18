/*
You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 

Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.

Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50

 

Constraints:

    n == nums.length
    1 <= nums.length <= 1000
    1 <= nums[i] <= 100
    1 <= left <= right <= n * (n + 1) / 2


*/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        return by_binary_search(nums, n, left, right);
    }
private:
    int mod = 1e9 + 7;
    std::pair<int, long long> cnt_sum(vector<int>& nums, int n, int target) {
        int cnt = 0;
        long long curr_sum = 0;
        long long total_sum = 0;
        long long window_sum = 0;

        for (int j = 0, i = 0; j < n; ++j) {
            curr_sum += nums[j];
            window_sum += nums[j] * (j - i + 1);

            while (curr_sum > target) {
                window_sum -= curr_sum;
                curr_sum -= nums[i];
                ++i;
            }

            cnt += j - i + 1;
            total_sum += window_sum;
        }

        return {cnt, total_sum};
    }

    long long sum_first_k(vector<int>& nums, int n, int k) {
        int min_sum = *std::min_element(nums.begin(), nums.end());
        int max_sum = std::accumulate(nums.begin(), nums.end(), 0);
        int left = min_sum;
        int right = max_sum;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (cnt_sum(nums, n, mid).first >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        auto [cnt, sum] = cnt_sum(nums, n, left);
        return sum - left * (cnt - k);
    }
    int by_binary_search(vector<int>& nums, int n, int left, int right) {
        long ans = (sum_first_k(nums, n, right) - sum_first_k(nums, n, left - 1)) % mod;

        return (ans + mod) % mod;
    }
};