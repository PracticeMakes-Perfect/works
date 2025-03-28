/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

    0 <= j <= nums[i] and
    i + j < n

Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

 

Constraints:

    1 <= nums.length <= 10^4
    0 <= nums[i] <= 1000
    It's guaranteed that you can reach nums[n - 1].


*/

class Solution {
private:
    int by_greedy(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        int curr_end = 0;
        int curr_farest = 0;
        int steps = 0;

        //because target is 'n-1', we use those smaller indices!
        for (int i = 0; i < n - 1; ++i) {
            curr_farest = std::max(curr_farest, i + nums[i]);

            if (i == curr_end) {
                ++steps;
                curr_end = curr_farest;
            }
        }
        return steps;
    }
    int by_iterative_dp(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        std::vector<int> dp(n, n);
        dp[0] = 0;
        for(int i = 1; i < n; ++i) {

            for (int j = 0; j < i; ++j) {

                if (j + nums[j] >= i) {
                    dp[i] = std::min(dp[i], 1 + dp[j]);
                }
            }
        }

        return dp[n - 1];
    }
public:
    int jump(vector<int>& nums) {
        return by_greedy(nums);
        //return by_iterative_dp(nums);
    }
};
