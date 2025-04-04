/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

 

Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

Example 2:

Input: x = 3, y = 1
Output: 1

 

Constraints:

    0 <= x, y <= 2^31 - 1


*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        /*
        int z = (x ^ y);
        int cnt = 0;
        
        while (z > 0) {
            if (z % 2 == 1) {
                cnt += 1;
            }
            
            z >>= 1;
        }

        return cnt;
        */

        //Brian Kernighan's Algorithm
        int doXor = (x ^ y);
        int dis = 0;
        while (doXor) {
            ++dis;
            doXor = doXor & (doXor - 1);
        }

        return dis;
    }
};