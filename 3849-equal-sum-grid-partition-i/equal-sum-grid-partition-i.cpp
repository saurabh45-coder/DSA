class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        // total sum
        for(auto &row : grid) {
            for(auto val : row) {
                total += val;
            }
        }

        if(total % 2 != 0) return false;

        long long target = total / 2;

        // 🔹 Horizontal cut check
        long long rowSum = 0;
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n; j++) {
                rowSum += grid[i][j];
            }
            if(rowSum == target) return true;
        }

        // // 🔹 Vertical cut check
        long long colSum = 0;
        for(int j = 0; j < n - 1; j++) {
            for(int i = 0; i < m; i++) {
                colSum += grid[i][j];
            }
            if(colSum == target) return true;
        }

        return false;
    }
};