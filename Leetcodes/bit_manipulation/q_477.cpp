/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

 

Example 1:

Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

Example 2:

Input: nums = [4,14,4]
Output: 4

 

Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 109
    The answer for the given input will fit in a 32-bit integer.


*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int N = nums.size();
        if (nums.size() == 1) {
            return 0;
        }
        int ans = 0;
        std::vector<int> cnt(32, 0);
        
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];

            int d = 0;
            while (val > 0) {
                cnt[d] += (val & 0x1);
                val >>= 1;
                ++d;
            }
        }

        for (const auto& k : cnt) {
            ans += k * (N - k);
        }

        return ans;
    }
};