vector<vector<bool>> visited; int n, m;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

void flood_fill(vector<vector<char>>& grid, int r, int c) {
    visited[r][c] = true;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == '1') flood_fill(grid, nr, nc);
    }
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0; n = grid.size(); m = grid[0].size(); visited.assign(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(!visited[i][j] && grid[i][j] == '1') {
                flood_fill(grid, i, j);
                count++;
            }
        }
        return count;
    }
};