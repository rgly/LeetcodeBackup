// Time : Beats 100%
// Memory : Beats 80.29%
class Solution {
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		const int m = heights.size();
		const int n = heights.front().size();
		vector<vector<bool>> atlantic(m, vector<bool>(n, false));
		vector<vector<bool>> placific(m, vector<bool>(n, false));
		
		auto dfs_if_higher =
				[&heights]
				(auto&& self,
					vector<vector<bool>>& covered,
					int val, int i, int j) -> void {
			if (heights[i][j] >= val) {
				self(covered, i, j);
			}
		};

		auto dfs = [&heights, &m, &n, &dfs_if_higher]
					(this auto&& self,
					vector<vector<bool>>& covered,
							int i, int j) -> void {
			if (covered[i][j]) return;
			else covered[i][j] = true;

			int val = heights[i][j];
			if (i>0)  dfs_if_higher(self, covered, val, i-1, j);
			if (j>0)  dfs_if_higher(self, covered, val, i, j-1);
			if (i<m-1)  dfs_if_higher(self, covered, val, i+1, j);
			if (j<n-1)  dfs_if_higher(self, covered, val, i, j+1);
		};

		// DFS
		for (int j=0; j<n; ++j) {
			dfs(atlantic, 0, j);
			dfs(placific, m-1, j);
		}
		for (int i=0; i<m; ++i) {
			dfs(atlantic, i, 0);
			dfs(placific, i, n-1);
		}

		// find intersection
		vector<vector<int>> ret;
		for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j) {
			if (atlantic[i][j] & placific[i][j]) {
				ret.push_back({i, j});
			}
		}
		return ret;
	}
};
