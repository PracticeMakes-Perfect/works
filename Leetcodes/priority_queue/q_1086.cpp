/*
Given a list of the scores of different students, items, where items[i] = [IDi, scorei] represents one score from a student with IDi, calculate each student's top five average.

Return the answer as an array of pairs result, where result[j] = [IDj, topFiveAveragej] represents the student with IDj and their top five average. Sort result by IDj in increasing order.

A student's top five average is calculated by taking the sum of their top five scores and dividing it by 5 using integer division.

 

Example 1:

Input: items = [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation: 
The student with ID = 1 got scores 91, 92, 60, 65, 87, and 100. Their top five average is (100 + 92 + 91 + 87 + 65) / 5 = 87.
The student with ID = 2 got scores 93, 97, 77, 100, and 76. Their top five average is (100 + 97 + 93 + 77 + 76) / 5 = 88.6, but with integer division their average converts to 88.

Example 2:

Input: items = [[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100]]
Output: [[1,100],[7,100]]

 

Constraints:

    1 <= items.length <= 1000
    items[i].length == 2
    1 <= IDi <= 1000
    0 <= scorei <= 100
    For each IDi, there will be at least five scores.


*/

class Solution {
private:
    vector<vector<int>> byPQ(vector<vector<int>>& items) {
        //by heap
        std::vector<std::priority_queue<int>> students(1001);

        for (auto& item : items)
            students[item[0]].push(item[1]);

        std::vector<std::vector<int>> ans;

        for (int i = 1; i <= 1000; i++) {
            int n = 0;
            int sum = 0;

            while (!students[i].empty() && n < 5) {
                sum += students[i].top();
                students[i].pop();
                n++;
            }

            if (n > 0)
                ans.push_back({i, sum / n});
        }

        return ans;
    }
    vector<vector<int>> naive(vector<vector<int>>& items) {
        
        //my naive way
        std::sort(items.begin(), items.end(), std::greater<std::vector<int>>());
        vector<vector<int>> result;

        int id = 0;
        for (int i = 0; i < items.size(); ++i) {

            id = items[i][0];
            int avg = 0;
            int start = i;
            int end = i + 5;
            while (start < end && end <= items.size()) {
                avg += items[start][1];
                ++start;
            }
            avg /= 5;
            result.push_back({id, avg});

            i = start;
            while (i < items.size() && items[i][0] == id) {
                ++i;
            }

            if (items[i - 1][0] == id) {
                i -= 1;
            }
        }

        std::sort(result.begin(), result.end());
        return result;
    }

public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {

        
        return byPQ(items);
        //return naive(items);
    }
};