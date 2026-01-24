// Time : Beats 86.02%
// Memory : Beats 91.03%
class Solution {
public:
	// djistra algorithm
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<vector<pair<int, int>>> edges(n+1);
		for (int i=0; i<times.size(); ++i) {
			auto s = times[i][0];
			auto d = times[i][1];
			auto t = times[i][2];
			edges[s].push_back({d,t});
		}

		vector<int> time(n+1, INT_MAX);
		time[k] = time[0] = 0;
		queue<int> q;
		q.push(k);
		while (!q.empty()) {
			int size = q.size();
			for (int i=0; i<size; ++i) {
				int s = q.front();
				q.pop();
				for (auto& p : edges[s]) {
					auto d = p.first;
					auto t = p.second;
					if (time[s] == INT_MAX) {
						continue;
					} else if (time[s] + t < time[d]) {
						time[d] = time[s] + t;
						q.push(d);
					}
				}
			}
		}
		int maxt = INT_MIN;
		for (auto t : time) {
			if (t == INT_MAX) return -1;
			maxt = max(maxt, t);
		}
		return maxt;
	}
};
