// Time : Beats 70.88%
// Time : Beats 77.20%
class Solution {
public:
	bool IsMeet(int p1, int s1, int p2, int s2, int target) {
		assert(target > p1);
		assert(p1 > p2);
		assert(s1 < s2);
		// float t1 = float(target-p1) / s1;
		// float t2 = float(target-p2) / s2;
		// return t2 <= t1;
		return long(target-p2) * s1 <= long(target-p1) * s2;
	}
	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		int n = position.size();
		if (n == 1) return 1;
		assert(n == speed.size());
		vector<pair<int, int>> status;
		for (int i=0; i<n; ++i) {
			int p = position[i];
			int s = speed[i];
			status.push_back({p, s});
		}
		sort(status.begin(), status.end());
		int fleet=1;
		auto [cur_pos, cur_speed] = status.back();
		for (int i=n-2; i>=0; --i) {
			auto& [p, s] = status[i];
			if (s <= cur_speed
			|| !IsMeet(cur_pos, cur_speed, p,s, target)) {
				cur_speed = s;
				cur_pos = p;
				++fleet;
			}
		}
		return fleet;
	}
};
