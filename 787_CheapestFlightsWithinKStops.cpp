// Time : Beats 66.05%
// Memory : Beats 51.03%
class Solution {
public:
	// from i, to i, price
	int findCheapestPrice(int n, vector<vector<int>>& flights,
						int src, int dst, int k) {
		if (src == dst) return 0;

		// directed Dijstra Algorithm for k times
		// build edges, src, [dst, price]
		vector<vector<pair<int, int>>> edges(n);
		for (auto v : flights) {
			int s = v[0];
			int d = v[1];
			int p = v[2];
			edges[s].push_back({d,p});
		}

		vector<int> prices(n, INT_MAX);
		prices[src] = 0;
		vector<int> prices2(prices);

		queue<int> jobs;
		jobs.push(src);
		for (int i=0; i<=k; ++i) {
			int jsize = jobs.size();
			for (int j=0; j<jsize; ++j) {
				int s = jobs.front();
				jobs.pop();
				for (auto dst_price : edges[s]) {
					int d = dst_price.first;
					int p = dst_price.second;
					if (prices[s]+p < prices2[d]) {
						jobs.push(d);
						prices2[d] = prices[s]+p;
					}
				}
			}
			prices = prices2;
		}
		if (prices[dst] == INT_MAX) return -1;
		else return prices[dst];
	}
};
