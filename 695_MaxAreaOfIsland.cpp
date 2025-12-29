// Time : Beats 100%
// Memory : Beats 67.85%
class Solution {
public:
	void dfs(vector<vector<int>>& grid, int i, int j, int& localArea) {
		if (grid[i][j] == 0) return;
		localArea += 1;
		grid[i][j] = 0;
		const int n = grid.size();
		const int m = grid[0].size();
		if (i>0) dfs(grid, i-1, j, localArea);
		if (j>0) dfs(grid, i, j-1, localArea);
		if (i<n-1) dfs(grid, i+1, j, localArea);
		if (j<m-1) dfs(grid, i, j+1, localArea);
	}
	int maxAreaOfIsland(vector<vector<int>>& grid){
		const int n = grid.size();
		if (n == 0) return 0;
		const int m = grid[0].size();
		if (m == 0) return 0;
		int MaxArea = 0;
		for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			int localArea = 0;
			dfs(grid, i, j, localArea);
			MaxArea = max(MaxArea, localArea);
		}
		}
		return MaxArea;
	}
};
