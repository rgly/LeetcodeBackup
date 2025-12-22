class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int groupSize) {
		map<int, int> cnt;
		for (auto v: hand) {
			if (cnt.count(v) == 0) cnt[v] =1;
			else ++cnt[v];
		}
		for (auto it=cnt.begin(); it!=cnt.end(); ++it) {
			auto [val, count] = *it;
			if (count ==0) continue;
			assert(count > 0);
			auto it2 = it;
			for (auto i=1; i<groupSize; ++i) {
				++it2;
				if (it2 != cnt.end()
					&& it2->first == val+i
					&& it2->second >= count) {
					it2->second -= count;
				} else {
					return false;
				}
			}
			it->second = 0;
		}
		return true;
	}
};
