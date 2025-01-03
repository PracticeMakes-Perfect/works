/*
A set of real numbers can be represented as the union of several disjoint intervals, where each interval is in the form [a, b). A real number x is in the set if one of its intervals [a, b) contains x (i.e. a <= x < b).

You are given a sorted list of disjoint intervals intervals representing a set of real numbers as described above, where intervals[i] = [ai, bi] represents the interval [ai, bi). You are also given another interval toBeRemoved.

Return the set of real numbers with the interval toBeRemoved removed from intervals. In other words, return the set of real numbers such that every x in the set is in intervals but not in toBeRemoved. Your answer should be a sorted list of disjoint intervals as described above.

 

Example 1:

Input: intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
Output: [[0,1],[6,7]]

Example 2:

Input: intervals = [[0,5]], toBeRemoved = [2,3]
Output: [[0,2],[3,5]]

Example 3:

Input: intervals = [[-5,-4],[-3,-2],[1,2],[3,5],[8,9]], toBeRemoved = [-1,4]
Output: [[-5,-4],[-3,-2],[4,5],[8,9]]

 

Constraints:

    1 <= intervals.length <= 10^4
    -10^9 <= ai < bi <= 10^9


*/

class Solution {
private: 
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int N = intervals.size();

        //corner case: begin of toBeRemoved is smaller than begin of smallest interval, 
        //and end of toBeRemoved is larger than end of largest interval
        if (toBeRemoved[0] <= intervals[0][0] && toBeRemoved[1] >= intervals[N - 1][1]) {
            return {};
        }

        std::vector<std::vector<int>> result;
        for (int i = 0; i < N; ++i) {
            if (intervals[i][0] > toBeRemoved[1] || intervals[i][1] < toBeRemoved[0]) {
                result.push_back(intervals[i]);
            } else {
                if (intervals[i][0] < toBeRemoved[0]) {
                    result.push_back({intervals[i][0], toBeRemoved[0]});
                }

                if (intervals[i][1] > toBeRemoved[1]) {
                    result.push_back({toBeRemoved[1], intervals[i][1]});
                }
            }
        }

        return result;
    }
};