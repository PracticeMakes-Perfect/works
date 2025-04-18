/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.

 

Constraints:

    -2^31 <= dividend, divisor <= 2^31 - 1
    divisor != 0


*/

class Solution {
private:
    int HALF_INT_MIN = -1073741824;
    int byBitsShift(int& dividend, int& divisor) {
        int negative = 2;
        if (dividend > 0) {
            --negative;
            dividend = -dividend;
        }
        if (divisor > 0) {
            --negative;
            divisor = -divisor;
        }

        int maxDouble = divisor;
        int maxPowOfTwo = -1;
        while (maxDouble >= HALF_INT_MIN && maxDouble + maxDouble >= dividend) {
            maxPowOfTwo += maxPowOfTwo;
            maxDouble += maxDouble;
        }

        int quotient = 0;
        while (dividend <= divisor) {
            if (dividend <= maxDouble) {
                quotient += maxPowOfTwo;
                dividend -= maxDouble;
            }

            maxPowOfTwo >>= 1;
            maxDouble >>= 1;
        }

        if (negative != 1) {
            return -quotient;
        }

        return quotient;
    }

    int byPowOfTwo(int& dividend, int& divisor) {
        
        int negative = 2;
        if (dividend > 0) {
            --negative;
            dividend = -dividend;
        }
        if (divisor > 0) {
            --negative;
            divisor = -divisor;
        }
        
        std::vector<int> doubles;
        std::vector<int> powsOfTwo;

        int powOfTwo = -1;
        while (divisor >= dividend) {
            doubles.push_back(divisor);
            powsOfTwo.push_back(powOfTwo);

            if (divisor < HALF_INT_MIN) {
                break;
            }

            divisor += divisor;
            powOfTwo += powOfTwo;
        }

        int quotient = 0;
        for (int i = doubles.size() - 1; i >= 0; --i) {
            if (doubles[i] >= dividend) {
                quotient += powsOfTwo[i];
                dividend -= doubles[i];
            }
        }

        if (negative != 1) {
            return -quotient;
        }

        return quotient;
    }
    int byRepeatedExponential(int& dividend, int& divisor) {

        int negative = 2;
        if (dividend > 0) {
            --negative;
            dividend = -dividend;
        }
        if (divisor > 0) {
            --negative;
            divisor = -divisor;
        }
        
        int quotient = 0;
        while (divisor >= dividend) {

            int powOfTwo = -1;
            int val = divisor;

            while (val >= HALF_INT_MIN && val + val >= dividend) {
                val += val;
                powOfTwo += powOfTwo;
            }

            quotient += powOfTwo;
            dividend -= val;
        }

        if (negative != 1) {
            quotient = -quotient;
        }

        return quotient;
    }
    int bySubtraction(int& dividend, int& divisor) {
        //corner case
        if (divisor == 1) {
            return dividend;
        }
        if (dividend == divisor) {
            return 1;
        }
        
        int negative = 2;
        if (dividend > 0) {
            --negative;
            dividend = -dividend;
        }
        if (divisor > 0) {
            --negative;
            divisor = -divisor;
        }
        
        int quotient = 0;
        while (dividend - divisor <= 0) {
            dividend -= divisor;
            --quotient;
        }

        if (negative != 1) {
            return -quotient;
        }
        return quotient;
    }

public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        //return bySubtraction(dividend, divisor);
        //return byRepeatedExponential(dividend, divisor);
        //return byPowOfTwo(dividend, divisor);
        return byBitsShift(dividend, divisor);
    }
};
