/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

    Only numbers 1 through 9 are used.
    Each number is used at most once.

Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

 

Constraints:

    2 <= k <= 9
    1 <= n <= 60


*/

class Solution {
private:
    std::vector<std::vector<int>> backtracking(int k, int n) {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;


        std::function<void(int, int, int)> bt = [&](int i_now, int rest_k, int rest_n) {
            if (rest_n == 0 && rest_k == 0) {
                ans.push_back(curr);
                return;
            }

            if (rest_n < 0 || rest_k <= 0) {
                return;
            }

            for (int i = i_now; i <= 9; ++i) {

                curr.push_back(i);
                bt(i + 1, rest_k - 1, rest_n - i);
                curr.pop_back();
            }
        };

        bt(1, k, n);
        
        return ans;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return backtracking(k, n);
    }
};