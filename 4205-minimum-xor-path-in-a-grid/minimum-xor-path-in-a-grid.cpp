class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<unordered_set<int>>> dp(
            n, vector<unordered_set<int>>(m)
        );

        dp[0][0].insert(grid[0][0]);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;

                if (i > 0) {
                    for (int x : dp[i-1][j]) {
                        dp[i][j].insert(x ^ grid[i][j]);
                    }
                }

                if (j > 0) {
                    for (int x : dp[i][j-1]) {
                        dp[i][j].insert(x ^ grid[i][j]);
                    }
                }
            }
        }

        return *min_element(
            dp[n-1][m-1].begin(),
            dp[n-1][m-1].end()
        );
    }
};