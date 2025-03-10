/*
You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.

 

Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.

Example 2:

Input: s = "", t = "y"
Output: "y"

 

Constraints:

    0 <= s.length <= 1000
    t.length == s.length + 1
    s and t consist of lowercase English letters.


*/

class Solution {
private:
    char bySort(string& s, string& t) {

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                return t[i];
            }
        }

        return t[t.size() - 1];
    }
    char byXOR(string& s, string& t) {
        char c = 0;

        //using bit manipulation XOR
        for (int i = 0; i < s.size(); ++i) {
            c ^= s[i];
        }

        for (int j = 0; j < t.size(); ++j) {
            c ^= t[j];
        }

        return c;
    }
public:
    char findTheDifference(string s, string t) {
        //return byXOR(s, t);

        return bySort(s, t);
    }
};