// Time : Beats 5.46%
// Memory : Beats 19.31%
// Even though dfs is log(n) complexity,
// Obviously, UnionFind with rank and path compression
// is a much fast way to detect circle
class Solution {
public:
	bool dfs(vector<vector<int>>& e, vector<bool>& used, int& firstOverlap, int node, int parent) {
		if (used[node]) {
			assert(firstOverlap == 0);
			firstOverlap = node;
			return true;
		} else {
			used[node] = true;
			for (auto n: e[node]) {
				if (parent == n) continue;
				if (firstOverlap != 0) break;
				if (dfs(e, used, firstOverlap, n, node)) {
					return (node != firstOverlap);
				}
			}
			used[node] = false;
		}
		return false;
	}
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n=0;
		vector<vector<int>> e;
		for (auto v: edges) {
			int a = v[0];
			int b = v[1];
			int max_ = max(a,b);
			if (max_ > n) {
				n = max_;
				e.resize(n+1);
			}
			e[a].push_back(b);
			e[b].push_back(a);
		}
		vector<bool> used(n+1);
		int firstOverlap=0;
		// circular detection
		dfs(e, used, firstOverlap, 1, 0);
		for (int i=edges.size()-1; i>=0; --i) {
			int a = edges[i][0];
			int b = edges[i][1];
			if (used[a] && used[b]) {
				return {a, b};
			}
		}
		return {};
	}
};
