/*
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.

Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.

 

Constraints:

    n == names.length == heights.length
    1 <= n <= 10^3
    1 <= names[i].length <= 20
    1 <= heights[i] <= 10^5
    names[i] consists of lower and upper case English letters.
    All the values of heights are distinct.


*/

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        std::vector<std::pair<int, std::string>> vals(n);

        for (int i = 0; i < n; ++i) {
            vals[i] = { heights[i], names[i] };
        }

        std::sort(vals.begin(), vals.end());
        std::vector<std::string> ans(n);
        for (int i = n - 1; i > -1; --i) {
            ans[i] = vals[n - 1 - i].second;
        }

        return ans;                    
    }
};