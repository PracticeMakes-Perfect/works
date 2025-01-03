/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.

Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

 

Constraints:

    n == nums.length
    1 <= n <= 2 * 10^5
    -10^9 <= nums[i] <= 10^9


*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }

        int n = nums.size();
        std::stack<int> stack;  //it stores all k!!
        std::vector<int> min_arr(n);
        min_arr[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            min_arr[i] = std::min(min_arr[i - 1], nums[i]);
        }

        for (int i = n - 1; i > 0; --i) {
            if (nums[i] <= min_arr[i]) {
                continue;
            }

            while (!stack.empty() && stack.top() <= min_arr[i]) {
                stack.pop();
            }

            if (!stack.empty() && stack.top() < nums[i]) {
                return true;
            }

            stack.push(nums[i]);
        }

        return false;
    }
};