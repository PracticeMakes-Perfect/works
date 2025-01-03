/*
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 

Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".

Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.

Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.

 

Constraints:

    1 <= s1.length, s2.length <= 100
    s1.length == s2.length
    s1 and s2 consist of only lowercase English letters.


*/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;

        int pos1 = 0;
        int pos2 = 0;
        for (int i = 0; i < s1.size(); ++i) {

            if (s1[i] != s2[i]) {

                ++cnt;
                if (cnt == 1) {
                    pos1 = i;
                } else if (cnt == 2) {
                    pos2 = i;
                }
            }

            if (cnt > 2) {
                return false;
            }
        }

        return s1[pos1] == s2[pos2] && s1[pos2] == s2[pos1];
    }
};