/*
You are given a positive integer k. You are also given:

    a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
    a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].

The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

    The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
    The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.

Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

 

Example 1:

Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.

Example 2:

Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.

 

Constraints:

    2 <= k <= 400
    1 <= rowConditions.length, colConditions.length <= 10^4
    rowConditions[i].length == colConditions[i].length == 2
    1 <= abovei, belowi, lefti, righti <= k
    abovei != belowi
    lefti != righti


*/

class Solution {
private:
    std::vector<int> topological_sort(std::vector<std::vector<int>>& edges, int n) {
        std::vector<std::vector<int>> adj(n + 1);
        std::vector<int> deg(n + 1);  //for indegree
        std::vector<int> order;

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            ++deg[e[1]];
        }

        std::queue<int> q;

        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int f = q.front();
            q.pop();
            order.push_back(f);
            --n;

            for (auto v : adj[f]) {
                if (--deg[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (n != 0) {
            return {};
        }

        return order;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        std::vector<int> ordered_rows = topological_sort(rowConditions, k);
        std::vector<int> ordered_cols = topological_sort(colConditions, k);

        if (ordered_rows.empty() || ordered_cols.empty()) {
            return {};
        }

        std::vector<std::vector<int>> ans(k, std::vector<int>(k));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (ordered_rows[i] == ordered_cols[j]) {
                    ans[i][j] = ordered_rows[i];
                }
            }
        }

        return ans;
    }
};