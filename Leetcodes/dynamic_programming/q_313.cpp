/*
A super ugly number is a positive integer whose prime factors are in the array primes.

Given an integer n and an array of integers primes, return the nth super ugly number.

The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

 

Example 1:

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].

Example 2:

Input: n = 1, primes = [2,3,5]
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].

 

Constraints:

    1 <= n <= 10^5
    1 <= primes.length <= 100
    2 <= primes[i] <= 1000
    primes[i] is guaranteed to be a prime number.
    All the values of primes are unique and sorted in ascending order.


*/

class Solution {
private:
    int by_iterative_dp(int& n, vector<int>& primes) {
        if (n == 1) {
            return 1;
        }

        int pn = primes.size();
        std::vector<int> times_of_prime(pn);
        std::vector<int> dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            unsigned int min_val = UINT_MAX;

            for (int j = 0; j < pn; ++j) {
                min_val = std::min(min_val, (unsigned int)dp[times_of_prime[j]] * primes[j]);
            }

            for (int j = 0; j < pn; ++j) {
                if (min_val == (unsigned int)dp[times_of_prime[j]] * primes[j]) {
                    ++times_of_prime[j];
                }
            }

            dp[i] = min_val;
        }

        return dp[n - 1];
    }
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        return by_iterative_dp(n, primes);
    }
};