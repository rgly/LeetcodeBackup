// Time : Beats  39.70%
// Memory : Beats 27.69%
// I use the theoretcally fastest Kahn's algorithm,
// which is linear complexity
class Solution {
public:
	void decDegAndPushQueue(vector<vector<int>>& matrix,
				vector<vector<int>>& degree,
				queue<pair<int, int>>& jobs,
				int i, int j, int val) {
		if (matrix[i][j] > val) {
			--degree[i][j];
			if (degree[i][j] == 0) {
				jobs.push({i,j});
			}
		}
	}
	// This is a DAG problem to find longest path
	// use Kahn's algorithm to sort and count levels as well
	// Complexity : O(V+E)
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix.front().size();
		vector<vector<int>> degree(m, vector<int>(n));
		queue<pair<int, int>> jobs;
		// set degree
		for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j) {
			int val = matrix[i][j];
			int deg = 0;
			if (i>0 && matrix[i-1][j] < val) ++deg;
			if (j>0 && matrix[i][j-1] < val) ++deg;
			if (i<m-1 && matrix[i+1][j] < val) ++deg;
			if (j<n-1 && matrix[i][j+1] < val) ++deg;
			degree[i][j] = deg;
			if (deg == 0) jobs.push({i,j});
		}
		int lvl=0;
		while (!jobs.empty()) {
			++lvl;
			int size = jobs.size();
			for (int x=0; x<size; ++x) {
				int i = jobs.front().first;
				int j = jobs.front().second;
				jobs.pop();

				// decrease degree of succ nodes
				// put to queue if deg==0
				int val = matrix[i][j];
				if (i>0) decDegAndPushQueue(matrix,
							degree, jobs, i-1, j, val);
				if (j>0) decDegAndPushQueue(matrix,
							degree, jobs, i, j-1, val);
				if (i<m-1) decDegAndPushQueue(matrix,
							degree, jobs, i+1, j, val);
				if (j<n-1) decDegAndPushQueue(matrix,
							degree, jobs, i, j+1, val);
				
			}
		}
		return lvl;
	}
};
