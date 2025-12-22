class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		for (int i=0; i< m; ++i) {
			for (int j=0; j<n; ++j) {
				int prev_path_sum = INT_MAX;
				if (i != 0) prev_path_sum = grid[i-1][j];
				if (j != 0) prev_path_sum = min(prev_path_sum, grid[i][j-1]);
				if (i!= 0 || j!=0) grid[i][j] += prev_path_sum; 
			}
		}
		return grid.back().back();
	}
};
