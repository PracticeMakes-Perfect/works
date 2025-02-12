/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

 

Constraints:

    1 <= nums.length <= 8
    -10 <= nums[i] <= 10


*/

class Solution {
private:
    void back_tracking(int& len, std::unordered_map<int, int>& m, std::vector<std::vector<int>>& ans, std::vector<int>&& curr) {
        if (curr.size() == len) {
            ans.push_back(curr);
            return;
        }

        for (auto& p : m) {

            if (p.second == 0) {
                continue;
            }
            
            curr.push_back(p.first);
            --m[p.first];

            back_tracking(len, m, ans, std::move(curr));

            curr.pop_back();
            ++m[p.first];
        }
    }
    vector<vector<int>> by_back_tracking(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::unordered_map<int, int> m;

        for (int& v : nums) {
            ++m[v];
        }

        int len = nums.size();
        back_tracking(len, m, ans, std::vector<int>());

        return ans;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        return by_back_tracking(nums);
    }
};

/*
class Solution {
private:
    vector<vector<int>> backtrack(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::unordered_map<int, int> m;
        int N = nums.size();

        for (int v : nums) {
            ++m[v];
        }

        std::vector<int> combination;
        std::function<void()> bt = [&]() {
            if (combination.size() == N) {
                ans.push_back(combination);
                return;
            }

            for (auto& p : m) {
                int n = p.first;
                int cnt = p.second;

                if (cnt == 0) {
                    continue;
                }

                combination.push_back(n);
                --m[n];

                bt();

                combination.pop_back();
                ++m[n];
            }
        };

        bt();

        return ans;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        return backtrack(nums);
    }
};
*/