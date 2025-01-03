/*
Given an integer n, return true if and only if it is an Armstrong number.

The k-digit number n is an Armstrong number if and only if the kth power of each digit sums to n.

 

Example 1:

Input: n = 153
Output: true
Explanation: 153 is a 3-digit number, and 153 = 13 + 53 + 33.

Example 2:

Input: n = 123
Output: false
Explanation: 123 is a 3-digit number, and 123 != 13 + 23 + 33 = 36.

 

Constraints:

    1 <= n <= 10^8


*/

class Solution {
public:
    bool isArmstrong(int n) {
        int m = n;

        std::vector<int> digits;
        while (m > 0) {
            int d = m % 10;
            digits.push_back(d);            

            m /= 10;
        }

        int sum = 0;
        int len = digits.size();
        for (int i = 0; i < len; ++i) {
            sum += std::pow(digits[i], len);
        }

        return sum == n;
    }
};