// Time: Beats 100%
// Memory: Beats 83.11%
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		if (k==0) return {};
		if (nums.empty()) return {};
		unordered_map<int, int> cntm;
		for (auto v: nums) {
			if (cntm.count(v) ==0) {
				cntm[v] = 1;
			} else {
				++cntm[v];
			}
		}
		// heap of freq, value
		priority_queue<pair<int, int>> maxheap;
		for (auto p : cntm) {
			auto [val, count] = p;
			maxheap.push({count, val});
		}
		vector<int> ret;
		for (int i=0; i<k; ++i) {
			ret.push_back(maxheap.top().second);
			maxheap.pop();
		}
		return ret;
	}
};
