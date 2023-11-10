// leetcode

/*
 class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        const int numRows = grid.size();
        const int numCols = grid[0].size();
        const std::vector<int> moves{0, 1, 0, -1, 0};

        auto isRottenNearby = [&](int row, int col, const std::vector<std::vector<int>>& grid) {
            for (int k = 0; k < 4; ++k) {
                const int newRow = row + moves[k];
                const int newCol = col + moves[k + 1];
                if (newRow < 0 || newRow == numRows || newCol < 0 || newCol == numCols)
                    continue;
                if (grid[newRow][newCol] == 2)
                    return true;
            }
            return false;
        };

        int timeElapsed = 0;

        while (true) {
            std::vector<std::vector<int>> nextGrid(numRows, std::vector<int>(numCols));

            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < numCols; ++j) {
                    if (grid[i][j] == 1) {
                        if (isRottenNearby(i, j, grid))
                            nextGrid[i][j] = 2;
                        else
                            nextGrid[i][j] = 1;
                    } else if (grid[i][j] == 2) {
                        nextGrid[i][j] = 2;
                    }
                }
            }

            if (nextGrid == grid)
                break;

            grid = nextGrid;
            ++timeElapsed;
        }

        return std::any_of(grid.begin(), grid.end(),
            [](const std::vector<int>& row) {
                return std::any_of(row.begin(), row.end(), [](int orange) {
                    return orange == 1;
                });
            }) ? -1 : timeElapsed;
    }
};

*/