// Time : Beats 100%
// Memory : Beats 65.59%
class Solution {
public:
	// path from grid[0, 0] to grid[n-1, n-1]
	// find minimum of "max of the path number"
	// This problem can be solve using binary
	// search of final answer
	// complexity is nlog(n)
	bool dfs(vector<vector<int>>& grid,
			vector<vector<bool>>& used,
			int water, int i, int j) {
		int n = grid.size();
		if (used[i][j] || grid[i][j] > water) return false;
		if (i == n-1 && j == n-1) return true;

		used[i][j] = true;
		if (i>0 && dfs(grid, used, water, i-1, j) ) return true;
		if (j>0 && dfs(grid, used, water, i, j-1) ) return true;
		if (i<n-1 && dfs(grid, used, water, i+1, j) ) return true;
		if (j<n-1 && dfs(grid, used, water, i, j+1) ) return true;
		return false;
	}
	bool swimInWater(vector<vector<int>>& grid, int water) {
		int n = grid.size();
		vector<vector<bool>> used(n, vector<bool>(n, false));

		return dfs(grid, used, water, 0, 0);
	}
	int swimInWater(vector<vector<int>>& grid) {
		// estimate number range
		int n = grid.size();
		int gridmax = INT_MIN;
		int gridmin = INT_MAX;
		for (auto row : grid)
		for (auto ele : row) {
			gridmin = min(gridmin, ele);
			gridmax = max(gridmax, ele);
		}
		gridmin = max(gridmin,
					max(grid[0][0], grid[n-1][n-1]));

		// binary search
		int u = gridmax;
		int l = gridmin;
		while (l < u) {
			int mid = (u+l)/2;
			bool val = swimInWater(grid, mid);
			if (val) 	u = mid;
			else 		l = mid+1;
		}
		assert(l==u);
		return l;
	}
};
