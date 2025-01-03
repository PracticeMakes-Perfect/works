/*
Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 

Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].

Example 2:

Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].

 

Constraints:

    0 <= low <= high <= 10^9

*/

class Solution {
public:
    int countOdds(int low, int high) {
        /*
        int o_low = low;
        int count = 0;
        
        if (low % 2 != 0) {
            count += 1;
            low += 2;
        } else {
            low += 1;
        }
        
        for (int i = low; i < high; i+=2) {
            ++count;
        }
        
        if (high % 2 != 0 && high != o_low) {
            count += 1;
        }
        
        return count;
        */
        
        //by mathematics
        int res = (high-low)/2;
        if(low %2 != 0 || high%2 != 0) {
            res++;
        }
            
        return res;
    }
};
