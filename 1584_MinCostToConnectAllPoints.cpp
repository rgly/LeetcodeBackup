// Time : Beats 83.49%
// Memory : Beats 75.82%
class Solution {
public:
	// Prim's algorithm
	int minkey(vector<int>& key, vector<bool>& mstSet) {
		const int n = key.size();
		int minval = INT_MAX;
		int minidx;
		for (int i=0; i<n; ++i) {
			if (!mstSet[i] && key[i] < minval) {
				minidx = i;
				minval = key[i];
			}
		}
		return minidx;
	}
	int minimunSpaningTree(vector<vector<int>>& edges) {
		const int n = edges.size();
		int cost = 0;
		vector<bool> mstSet(n, false);
		vector<int> parent(n);
		vector<int> key(n, INT_MAX);
		// init
		parent[0] = -1;
		key[0] = 0;
		for (int i=0; i<n; ++i) {
			int u = minkey(key, mstSet);
			mstSet[u] = true;
			if (parent[u] != -1) {
				cost += edges[parent[u]][u];
			}
			// update key
			for (int v=0; v<n; ++v) {
				if (!mstSet[v] && edges[u][v] < key[v]) {
					key[v] = edges[u][v];
					parent[v] = u;
				}
			}
		}
		return cost;
	}

	int minCostConnectPoints(vector<vector<int>>& points) {
		const int n = points.size();
		if (n<=1) return 0;
		vector<vector<int>> edges(n, vector<int>(n));
		for (int i=0; i<n-1; ++i) {
			for (int j=i+1; j<n; ++j) {
				int xi = points[i][0];
				int yi = points[i][1];
				int xj = points[j][0];
				int yj = points[j][1];
				int cost = abs(xi-xj) + abs(yi-yj);
				edges[i][j] = cost;
				edges[j][i] = cost;
			}
		}
		return minimunSpaningTree(edges);
	}
};
