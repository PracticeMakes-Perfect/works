/*
You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

 

Example 1:

Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.

Example 2:

Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 1000
    1 <= m * n <= 10^5
    1 <= grid[i][j] <= 10^5


*/

class Solution {
private:
    int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    int recursive(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& mem) {

        //mem[r][c] != -1 as visited!!!
        if (mem[r][c] != -1) {
            return mem[r][c];
        }

        //use the r, c as end point, find its prev neighbors that are smaller than it!!
        //we could do it in reverse, start from r, c, find its next neighbors that are larger than it!!
        int ans = 1;
        for (auto& v : dir) {
            int prev_r = r + v[0];
            int prev_c = c + v[1];

            if (prev_r >= 0 && prev_r < grid.size() && 
                    prev_c >= 0 && prev_c < grid[0].size() && 
                                grid[prev_r][prev_c] < grid[r][c]) {

                ans += recursive(grid, prev_r, prev_c, mem);
                ans %= 1000000007;
            }
        }

        return mem[r][c] = ans;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<std::vector<int>> mem(rows, std::vector<int>(cols, -1));

        int ans = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                ans = (ans + recursive(grid, r, c, mem)) % 1000000007;
            }
        }

        return ans;
    }
};