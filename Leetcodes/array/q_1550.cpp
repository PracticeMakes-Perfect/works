/*
Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

 

Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.

Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.

 

Constraints:

    1 <= arr.length <= 1000
    1 <= arr[i] <= 1000

*/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        int cnt = 0;
        for (int i = 0; i < arr.size(); ++i) {

            if (arr[i] % 2) {
                ++cnt;
            } else {
                cnt = 0;
            }

            if (cnt == 3) {
                return true;
            }
        }

        return false;
    }
};