/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:

Input: nums = [1,2,3]
Output: 3

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 1000


*/

class Solution {
private:
    int iterative(vector<int>& nums, int b, int e) {
        /*
        std::vector<int> dp(nums.size() + 1);
        dp[b] = nums[b];
        dp[b + 1] = std::max(nums[b + 1], nums[b]);

        for (int i = b + 2; i <= e; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[e];
        */

        int rob1 = nums[b];
        int rob2 = std::max(nums[b + 1], nums[b]);

        for (int i = b + 2; i <= e; ++i) {
            int rob3 = std::max(rob2, rob1 + nums[i]);
            rob1 = rob2;
            rob2 = rob3;
        }

        return rob2;
    }
    int by_iterative_dp(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        if (n == 2) {
            return std::max(nums[0], nums[1]);
        }

        int from_first = iterative(nums, 0, n - 2);
        int from_sec = iterative(nums, 1, n - 1);

        return std::max(from_first, from_sec);
    }
public:
    int rob(vector<int>& nums) {
        return by_iterative_dp(nums);
    }
};