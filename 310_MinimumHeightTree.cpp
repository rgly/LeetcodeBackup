// Time : Beats 47.11%
// Memory : Beats 36.62%
// ref : https://algo.monster/liteproblems/310
class Solution {
public:
	// remove the leaf nodes until last iteration (1 or 2 nodes remained)
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n==0) return {};
		if (n==1) return {0};
		vector<vector<int>> e(n);
		vector<int> degree(n, 0);
		for (auto vec : edges) {
			int a = vec[0];
			int b = vec[1];
			e[b].push_back(a);
			e[a].push_back(b);
			++degree[a];
			++degree[b];
		}
		queue<int> leavs;
		for (int i=0; i<n; ++i) {
			if (degree[i] == 1) leavs.push(i);
		}
		vector<int> ret;
		while (!leavs.empty()) {
			ret.clear();
			int size = leavs.size();
			for (int k=0; k<size; ++k) {
				int i = leavs.front();
				leavs.pop();
				ret.push_back(i);
				for (int j : e[i]) {
					--degree[j];
					if (degree[j]==1) {
						leavs.push(j);
					}
				}
			}
		}
		return ret;
	}
};
