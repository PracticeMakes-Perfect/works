/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

 

Constraints:

    nums.length == k
    1 <= k <= 3500
    1 <= nums[i].length <= 50
    -10^5 <= nums[i][j] <= 10^5
    nums[i] is sorted in non-decreasing order.


*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        std::priority_queue<std::pair<int, std::pair<int, int>>, 
                            std::vector<std::pair<int, std::pair<int, int>>>, 
                            std::greater<std::pair<int, std::pair<int, int>>>> pq;

        int max_val = INT_MIN;
        int range_b = 0;
        int range_e = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i][0], {i, 0}});
            max_val = std::max(max_val, nums[i][0]);
        }

        while (pq.size() == nums.size()) {
            auto [min_val, indices] = pq.top();
            pq.pop();
            int row = indices.first;
            int col = indices.second;

            if (max_val - min_val < range_e - range_b) {
                range_b = min_val;
                range_e = max_val;
            }

            if (col + 1 < nums[row].size()) {
                int next_val = nums[row][col + 1];
                pq.push({next_val, {row, col + 1}});
                max_val = std::max(max_val, next_val);
            }
        }

        return {range_b, range_e};
    }
};