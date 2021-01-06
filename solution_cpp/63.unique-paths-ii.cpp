/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.98%)
 * Likes:    1447
 * Dislikes: 223
 * Total Accepted:    271.9K
 * Total Submissions: 799.9K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dps(m, vector<int>(n, 0));
        dps[0][0] = 1;
        for (int i=1; i<m; ++i)
            dps[i][0] = dps[i-1][0] && !obstacleGrid[i][0];
        for (int j=1; j<n; ++j)
            dps[0][j] = dps[0][j-1] && !obstacleGrid[0][j];
        for (int i=1; i<m; ++i)
        {
            for (int j=1; j<n; ++j)
            {
                if (obstacleGrid[i][j]) continue;
                dps[i][j] = dps[i-1][j] + dps[i][j-1];
            }
        }
        return dps[m-1][n-1];
    }
};
// @lc code=end
