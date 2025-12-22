// Time : Beats 68.56%
// Memory : Beats 59.00%
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		if (points.empty()) return {{}};
		if (k==0) return {{}};
		typedef tuple<long, int, int> PTy;
		priority_queue<PTy> maxheap;
		for (auto& v : points) {
			int x = v[0];
			int y = v[1];
			long dis = x*x + y*y;
			PTy p = {dis, x, y};
			if (maxheap.size() < k) {
				maxheap.push(p);
			} else if (p < maxheap.top()) {
				maxheap.pop();
				maxheap.push(p);
			}
		}

		assert(maxheap.size() >= k);
		vector<vector<int>> ret;
		for (int i=0; i<k; ++i) {
			auto [l, x, y] = maxheap.top();
			maxheap.pop();
			ret.push_back({x, y});
		}
		return ret;
	}
};
