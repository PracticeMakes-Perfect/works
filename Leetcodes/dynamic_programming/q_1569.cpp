/*
Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

    For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.

Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [2,1,3]
Output: 1
Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.

Example 2:

Input: nums = [3,4,5,1,2]
Output: 5
Explanation: The following 5 arrays will yield the same BST: 
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]

Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: There are no other orderings of nums that will yield the same BST.

 

Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i] <= nums.length
    All integers in nums are distinct.


*/

class Solution {
private:
    int recursive(vector<int>& nums) {
        int N = nums.size();
        //combination table
        std::vector<std::vector<long long>> table(N + 1);
        long long mod = 1000000007;
        for (int i = 0; i < N + 1; ++i) {
            table[i] = std::vector<long long>(i + 1, 1);

            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i  - 1][j]) % mod;
            }
        }

        std::function<long long(std::vector<int>&)> dfs = [&](std::vector<int>& nums_now) -> long long {
            int M = nums_now.size();
            if (M < 3) {
                return 1;
            }

            std::vector<int> leftNodes;
            std::vector<int> rightNodes;
            for (int i = 1; i < M; ++i) {
                if (nums_now[i] < nums_now[0]) {
                    leftNodes.push_back(nums_now[i]);
                } else {
                    rightNodes.push_back(nums_now[i]);
                }
            }

            long long leftWays = dfs(leftNodes) % mod;
            long long rightWays = dfs(rightNodes) % mod;

            return (((leftWays * rightWays) % mod) * table[M - 1][leftNodes.size()]) % mod;
        };

        return (dfs(nums) - 1) % mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        return recursive(nums);
    }
};