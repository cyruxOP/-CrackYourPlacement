class Solution {
public:
 
    vector<int> findBall(vector<vector<int>>& grid) {
        
       vector<int> result(grid[0].size());  
       for (int i = 0; i < grid[0].size(); ++i) {
        int currRow = 0, currCol = i;
        while (currRow < grid.size()) {
            // We go to the right if the current value and the value to the right are both equal to 1.
            if (grid[currRow][currCol] == 1 && currCol + 1 < grid[0].size() && grid[currRow][currCol + 1] == 1) {
                currCol++; currRow++;
            // We go to the left if the current value and the value to the left are both equal to -1.
            } else if (grid[currRow][currCol] == -1 && currCol - 1 >= 0 && grid[currRow][currCol - 1] == -1) {
                currCol--; currRow++;
            } else {
                break;  // If we can't move to the left, and we can't move to the right, then the ball is stuck because there is no other way to move.
            }
        }
        result[i] = currRow == grid.size() ? currCol : -1;   // Store -1 if the ball got stuck.
    }
    return result;
    }
};