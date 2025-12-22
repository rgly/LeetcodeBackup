//Time: Beat 100%
//Memory: Beat 96.74%
class Solution {
public:
	void infect(vector<vector<int>>& grid,
					queue<pair<int,int>>& newrotten,
					int i, int j) {
		const int m = grid.size();
		const int n = grid[0].size();
		if (i>0 && grid[i-1][j]==1) newrotten.push({i-1,j});
		if (j>0 && grid[i][j-1]==1) newrotten.push({i,j-1});
		if (i<m-1 && grid[i+1][j]==1) newrotten.push({i+1,j});
		if (j<n-1 && grid[i][j+1]==1) newrotten.push({i,j+1});
	}
	int oragnesRotting(vector<vector<int>>& grid) {
		queue<pair<int,int>> newrotten;
		const int m = grid.size();
		const int n = grid[0].size();
		// collect all rotten orange at time 1
		for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			if (grid[i][j] == 2) infect(grid, newrotten, i, j);

		// infect the oranges
		int time = 0;
		while (!newrotten.empty()) {
			int size = newrotten.size();
			bool update=false;
			for(int z=0; z<size; ++z) {
				auto [i, j] = newrotten.front();
				newrotten.pop();
				if (grid[i][j] != 1) continue;
				grid[i][j] = 2;
				update=true;
				infect(grid, newrotten, i, j);
			}
			if (update) ++time;
		}

		// still have fresh oranges
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				if (grid[i][j] == 1) {
					return -1;
				}
			}
		}
		return time;
	}
};
