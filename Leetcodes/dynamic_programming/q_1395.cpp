/*
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

    Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
    A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).

Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 

Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.

Example 3:

Input: rating = [1,2,3,4]
Output: 4

 

Constraints:

    n == rating.length
    3 <= n <= 1000
    1 <= rating[i] <= 10^5
    All the integers in rating are unique.


*/

class Solution {
private:
    int iterative(vector<int>& rating) {
        int n = rating.size();
        std::vector<std::vector<int>> incr(n, std::vector<int>(4, 0));
        std::vector<std::vector<int>> decr(n, std::vector<int>(4, 0));

        for (int i = 0; i < n; ++i) {
            incr[i][1] = 1;
            decr[i][1] = 1;
        }

        for (int cnt = 2; cnt <= 3; ++cnt) {
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (rating[j] > rating[i]) {
                        incr[j][cnt] += incr[i][cnt - 1];
                    }

                    if (rating[j] < rating[i]) {
                        decr[j][cnt] += decr[i][cnt - 1];
                    }
                }
            }
        

        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += incr[i][3] + decr[i][3];
        }
        
        return ans;
    }
public:
    int numTeams(vector<int>& rating) {
        return iterative(rating);
    }
};