/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:

Input: grid = [[1]]
Output: 4

Example 3:

Input: grid = [[1,0]]
Output: 4

 

Constraints:

    row == grid.length
    col == grid[i].length
    1 <= row, col <= 100
    grid[i][j] is 0 or 1.
    There is exactly one island in grid.


*/

class Solution {
private:
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 1) {
                    perimeter += 4;
                    //check column bound
                    if (r > 0 && grid[r - 1][c] == 1) {

                        //if current cell is 'A' and up cell is 'B', and 'A' and 'B' are both land, 
                        //then top of 'A' will overlap with bottom of 'B', so we minus 2
                        perimeter -= 2;
                    } 
                    
                    if (c > 0 && grid[r][c  - 1] == 1) {
                        //same logic as above

                        perimeter -= 2;
                    } 
                }
            }
        }
        return perimeter;
    }
};