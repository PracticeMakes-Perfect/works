/*
Given a string s and an integer k, return the total number of substrings of s where at least one character appears at least k times.

A substring is a contiguous non-empty sequence of characters within a string.

 

Example 1:

Input: s = "abacb", k = 2

Output: 4

Explanation:

The valid substrings are:

    "aba" (character 'a' appears 2 times).
    "abac" (character 'a' appears 2 times).
    "abacb" (character 'a' appears 2 times).
    "bacb" (character 'b' appears 2 times).

Example 2:

Input: s = "abcde", k = 1

Output: 15

Explanation:

All substrings are valid because every character appears at least once.

 

Constraints:

    1 <= s.length <= 3000
    1 <= k <= s.length
    s consists only of lowercase English letters.


*/

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        if (n == 1) {
            return 1;
        }
        
        if (k == 1) {
            return (n + 1) * n / 2;
        }
        
        int cnt = 0;
        int b = 0;
        std::vector<int> m(26);
        
        for (int i = 0; i < n; ++i) {
            ++m[s[i] - 'a'];

            while (m[s[i] - 'a'] == k) {
                --m[s[b] - 'a'];
                ++b;
            }
            
            cnt += b;
        }
        
        
        return cnt;
    }
};