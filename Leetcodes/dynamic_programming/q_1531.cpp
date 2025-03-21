/*
Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.

 

Example 1:

Input: s = "aaabcccd", k = 2
Output: 4
Explanation: Compressing s without deleting anything will give us "a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' would at most decrease the length of the compressed string to 5, for instance delete 2 'a' then we will have s = "abcccd" which compressed is abc3d. Therefore, the optimal way is to delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.

Example 2:

Input: s = "aabbaa", k = 2
Output: 2
Explanation: If we delete both 'b' characters, the resulting compressed string would be "a4" of length 2.

Example 3:

Input: s = "aaaaaaaaaaa", k = 0
Output: 3
Explanation: Since k is zero, we cannot delete anything. The compressed string is "a11" of length 3.

 

Constraints:

    1 <= s.length <= 100
    0 <= k <= s.length
    s contains only lowercase English letters.


*/

class Solution {
private:
    int iterative(std::string& s, int k) {
        int n = s.size();
        int m = k;

        int dp[110][110] = {};
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i && j <= m; ++j) {
                int need_remove = 0;
                int group_count = 0;
                dp[i][j] = INT_MAX;
                if (j) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                for (int k = i; k >= 1; --k) {
                    if (s[k - 1] != s[i - 1]) {
                        need_remove += 1;
                    } else {
                        group_count += 1;
                    }

                    if (need_remove > j) {
                        break;
                    }

                    if (group_count == 1) {
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - need_remove] + 1);
                    } else if (group_count < 10) {
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - need_remove] + 2);
                    } else if (group_count < 100) {
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - need_remove] + 3);
                    } else {
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - need_remove] + 4);
                    }
                }
            }
        }

        return dp[n][m];
    }

    int recursive(string& s, int k, int i, std::vector<std::vector<int>>& mem) {
        int n = s.size();
        int k_now = k;

        if (n - i <= k_now) {
            return 0;
        }
        
        if (mem[i][k_now] != -1) {
            return mem[i][k_now];
        }

        int ans = k_now ? recursive(s, k_now - 1, i + 1, mem) : 101;
        int c = 1;

        for(int j = i + 1; j <= n; ++j){
            
            ans = std::min(ans, 1 + ((c > 99) ? 3 : (c > 9) ? 2 : (c > 1) ? 1 : 0) + 
                    recursive(s, k_now, j, mem));

            if (j < n && s[i] == s[j]) {
                ++c;
            } else if(--k_now < 0) {
                break;
            }
        }

        return mem[i][k] = ans;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        std::vector<std::vector<int>> mem(101, std::vector<int>(101, -1));
        return recursive(s, k, 0, mem);
        //return iterative(s, k);
    }
};