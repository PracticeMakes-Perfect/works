/*
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

 

Constraints:

    1 <= nums.length <= 10^5
    nums[i] is either 0 or 1.


*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int N = nums.size();
        std::vector<int> indices(2 * N + 1, -2);
        indices[N] = -1;

        int maxLen = 0;
        int cnt = 0;
        
        for (int i = 0; i < N; ++i) {
            cnt = cnt + (nums[i] == 0 ? -1 : 1);

            //indices contain index of nums, index > -1, we calculate max len
            if (indices[cnt + N] >= -1) {
                maxLen = std::max(maxLen, i - indices[cnt + N]);
            } else {
                indices[cnt + N] = i;
            }
            
        }

        return maxLen;
    }
};