class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int div) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && vis[i][j] == 0) {
                    long long sum=0;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        auto idx = q.front();
                        q.pop();
                        int row = idx.first;
                        int col = idx.second;
                        sum += grid[row][col];
                        for (int k = 0; k < 4; k++) {
                            int nr = dr[k] + row;
                            int nc = dc[k] + col;
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                                vis[nr][nc] == 0 && grid[nr][nc] != 0) {

                                q.push({nr, nc});
                                vis[nr][nc] = 1;
                            }
                        }
                    }
                    if (sum % div == 0)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};