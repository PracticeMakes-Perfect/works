/*
Given a 2D matrix matrix, handle multiple queries of the following type:

    Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Implement the NumMatrix class:

    NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
    int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

You must design an algorithm where sumRegion works on O(1) time complexity.

 

Example 1:

Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 200
    -10^4 <= matrix[i][j] <= 10^4
    0 <= row1 <= row2 < m
    0 <= col1 <= col2 < n
    At most 104 calls will be made to sumRegion.


*/

class NumMatrix {
private:
    std::vector<std::vector<int>> copy;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        copy.resize(matrix.size() + 1, std::vector<int>(matrix[0].size() + 1, 0));

        for (int r = 0; r < matrix.size(); ++r) {
            for (int c = 0; c < matrix[0].size(); ++c) {
                copy[r + 1][c + 1] = copy[r + 1][c] + copy[r][c + 1] + matrix[r][c] - copy[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return copy[row2 + 1][col2 + 1] + copy[row1][col1] - copy[row2 + 1][col1] - copy[row1][col2 + 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */