// Time : Beats 25.07%
// Memory : Beats 20.13%
class Solution {
public:
	// This is a DAG problem to find longest path
	// Edges : elements to other elements with larger num
	// Complexity : nlog(n)
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix.front().size();
		// sort graph first
		// val, i, j
		vector<tuple<int, int, int>> graph;
		for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j) {
			int val = matrix[i][j];
			graph.push_back({val, i, j});
		}
		sort(graph.begin(), graph.end());

		// store longest path in every elements.
		int val, i, j;
		int longest = 0;
		vector<vector<int>> pathlen(m, vector<int>(n));
		for (auto& t : graph) {
			tie(val, i, j) = t;
			int cur_max = 0;
			if (i>0 && matrix[i-1][j] < val)
				cur_max = max(cur_max, pathlen[i-1][j]);
			if (j>0 && matrix[i][j-1] < val)
				cur_max = max(cur_max, pathlen[i][j-1]);
			if (i<m-1 && matrix[i+1][j] < val)
				cur_max = max(cur_max, pathlen[i+1][j]);
			if (j<n-1 && matrix[i][j+1] < val)
				cur_max = max(cur_max, pathlen[i][j+1]);
			pathlen[i][j] = cur_max+1;
			longest = max(longest, pathlen[i][j]);
		}
		return longest;
	}
};
