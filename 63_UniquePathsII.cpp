class Solution {
public:
	int uniquePathWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		int hasPath = 1;
		for (int i=0; i< m; ++i) {
			if (obstacleGrid[i][0]) hasPath=0;
			obstacleGrid[i][0] = hasPath;
		}
		hasPath = obstacleGrid[0][0];
		for (int j=0; j< n; ++j) {
			if (obstacleGrid[0][j]) hasPath=0;
			obstacleGrid[0][j] = hasPath;
		}

		for (int i=1; i< m; ++i) {
			for (int j=1; j<n; ++j) {
				if (obstacleGrid[i][j]) {
					obstacleGrid[i][j] = 0;
				} else {
					int up = obstacleGrid[i-1][j];
					int left = obstacleGrid[i][j-1];
					obstacleGrid[i][j] = up+left;
				}
			}
		}
		return obstacleGrid.back().back();
	}
};
