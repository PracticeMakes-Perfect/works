/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

    "AAJF" with the grouping (1 1 10 6)
    "KJF" with the grouping (11 10 6)

Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.


Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").

 
Constraints:

    1 <= s.length <= 100
    s contains only digits and may contain leading zero(s).

*/

class Solution {
private:
    int iterative(std::string& s) {
        int n = s.size();
        if (n == 1) {
            return s[0] == '0' ? 0 : 1; 
        }

        std::vector<int> dp(n + 1); //it means length
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        for (int i = 2; i <= n; ++i) {

            //one digit
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            //two digit
            int val = std::stoi(s.substr(i - 2, 2));
            if (val >= 10 && val <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
    int recurisve(std::string& s, int i, std::vector<int>& mem) {
        //we could not decode any sub-string starts from '0'
        if (s[i] == '0') {
            return 0;
        }

        if (i >= s.size() - 1) {
            return 1;
        }

        if (mem[i] != -1) {
            return mem[i];
        }

        //from the requirement, 
        //we could expect the max length for transforming number to character is 2
        int ans = recurisve(s, i + 1, mem);
        if (std::stoi(s.substr(i, 2)) <= 26) {
            ans += recurisve(s, i + 2, mem);
        }

        mem[i] = ans;
        return ans;
    }
public:
    int numDecodings(string s) {
        //std::vector<int> mem(s.size(), -1);
        //return recurisve(s, 0, mem);

        return iterative(s);
    }
};