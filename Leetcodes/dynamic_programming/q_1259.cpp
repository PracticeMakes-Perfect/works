/*
You are given an even number of people numPeople that stand around a circle and each person shakes hands with someone else so that there are numPeople / 2 handshakes total.

Return the number of ways these handshakes could occur such that none of the handshakes cross.

Since the answer could be very large, return it modulo 109 + 7.

 

Example 1:

Input: numPeople = 4
Output: 2
Explanation: There are two ways to do it, the first way is [(1,2),(3,4)] and the second one is [(2,3),(4,1)].

Example 2:

Input: numPeople = 6
Output: 5

 

Constraints:

    2 <= numPeople <= 1000
    numPeople is even.


*/

class Solution {
public:
    int numberOfWays(int numPeople) {
        const int m = 1'000'000'007;
        std::vector<int> dp(numPeople / 2 + 1);
        dp[0] = 1;

        //separate people into two parts
        //j for the people in the left part
        for (int i = 1; i <= numPeople / 2; ++i) {
            for (int j = 0; j < i; ++j) {
                 (dp[i] += (long long)dp[j] * dp[i - j - 1] % m) %= m;
            }
        }

        return dp[numPeople / 2];
    }
};