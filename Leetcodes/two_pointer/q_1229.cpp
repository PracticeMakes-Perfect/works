/*
Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration, return the earliest time slot that works for both of them and is of duration duration.

If there is no common time slot that satisfies the requirements, return an empty array.

The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.

 

Example 1:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
Output: [60,68]

Example 2:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
Output: []

 

Constraints:

    1 <= slots1.length, slots2.length <= 10^4
    slots1[i].length, slots2[i].length == 2
    slots1[i][0] < slots1[i][1]
    slots2[i][0] < slots2[i][1]
    0 <= slots1[i][j], slots2[i][j] <= 10^9
    1 <= duration <= 10^6


*/

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        std::sort(slots1.begin(), slots1.end());
        std::sort(slots2.begin(), slots2.end());

        int p1 = 0;
        int p2 = 0;
        std::vector<int> ans;
        while (p1 < slots1.size() && p2 < slots2.size()) {

            if (slots1[p1][0] > slots2[p2][1]) {
                ++p2;
            } else if (slots1[p1][1] < slots2[p2][0]) {
                ++p1;
            } else {

                int b = std::max(slots1[p1][0], slots2[p2][0]);
                int e = std::min(slots1[p1][1], slots2[p2][1]);
                if (e - b < duration) {
                    
                    if (slots1[p1][1] < slots2[p2][1]) {
                        ++p1;
                    } else {
                        ++p2;
                    }

                } else {
                    ans.emplace_back(b);
                    ans.emplace_back(b + duration);
                    break;
                }
            }
        }

        return ans;
    }
};