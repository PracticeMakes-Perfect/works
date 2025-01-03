/*
Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

    Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
    Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
    The prefix and the suffix should not intersect at any index.
    The characters from the prefix and suffix must be the same.
    Delete both the prefix and the suffix.

Return the minimum length of s after performing the above operation any number of times (possibly zero times).

 

Example 1:

Input: s = "ca"
Output: 2
Explanation: You can't remove any characters, so the string stays as is.

Example 2:

Input: s = "cabaabac"
Output: 0
Explanation: An optimal sequence of operations is:
- Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
- Take prefix = "a" and suffix = "a" and remove them, s = "baab".
- Take prefix = "b" and suffix = "b" and remove them, s = "aa".
- Take prefix = "a" and suffix = "a" and remove them, s = "".

Example 3:

Input: s = "aabccabba"
Output: 3
Explanation: An optimal sequence of operations is:
- Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
- Take prefix = "b" and suffix = "bb" and remove them, s = "cca".

 

Constraints:

    1 <= s.length <= 10^5
    s only consists of characters 'a', 'b', and 'c'.


*/

class Solution {
private:
    int byTwoPtr(std::string& s) {
        int N = s.size();
        int left = 0;
        int right = N - 1;

        while (left < right && s[left] == s[right]) {
            char c = s[left];

            while (left <= right && s[left] == c) {
                ++left;
            }

            while (right > left && s[right] == c) {
                --right;
            }
        }

        return right - left + 1;
    }
public:
    int minimumLength(string s) {
        return byTwoPtr(s);
    }
};