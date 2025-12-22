class Solution {
public:
	void checkNeighbor(
				vector<vector<int>>& mat,
				int i, int j,
				vector<vector<bool>>& used,
				queue<pair<int,int>>& next) {
		if (i>0 && mat[i-1][j]!=0 && !used[i-1][j]) {
			next.push({i-1, j});
			used[i-1][j] = true;
		}
		if (j>0 && mat[i][j-1]!=0 && !used[i][j-1]) {
			next.push({i, j-1});
			used[i][j-1] = true;
		}
		if (i<mat.size()-1 && mat[i+1][j]!=0 && !used[i+1][j]) {
			next.push({i+1, j});
			used[i+1][j] = true;
		}
		if (j<mat[0].size()-1 && mat[i][j+1]!=0 && !used[i][j+1]) {
			next.push({i, j+1});
			used[i][j+1] = true;
		}
	}
	vector<vector<int>> updateMatrix(vector<vector<int>& mat) {
		const int m = mat.size();
		if (m==0) return {{}};
		const int n = mat.front().size();
		vector<vector<bool> used(m, vector<bool>(n, false));
		queue<pair<int,int>> jobs;
		for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j) {
			if (mat[i][j] == 0) {
				checkNeighbor(mat, i, j, used, jobs);
				used[i][j] = true;
			}
		}
		}
		int step=1;
		while (!jobs.empty()) {
			queue<pair<int,int>> next;
			while (!jobs.empty()) {
				auto [i, j] = jobs.front();
				jobs.pop();
				checkNeighbor(mat, i, j, used, next);
				mat[i][j] = step;
			}
			jobs = next;
			++step;
		}
		return mat;
	}
};
