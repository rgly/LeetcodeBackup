// Time : Beats 16.83%
// Memory : Beats 12.87%
// Idea is
class Solution {
public:
	bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
		// traverse triplets to find
		// 1. triplet_i = target_i & other index j < target_j
		// until all index have equal ones.
		array<bool, 3> indexs = {false};
		for (auto triplet: triplets) {
			array<bool, 3> tmp = {false};
			bool breakcond = false;
			for (int i=0; i<3; ++i) {
				if (triplet[i] > target[i]) {
					breakcond = true;
					break;
				} else if (triplet[i] == target[i]) {
					tmp[i] = true;
				}
			}
			if (breakcond) continue;
			for (int i=0; i<3; ++i) {
				indexs[i] |= tmp[i];
			}
		}
		bool ret = true;
		for (int i=0; i<3; ++i) {
			ret &= indexs[i];
		}
		return ret;
	}
	// second implementation
	bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
		// traverse triplets to find
		// 1. triplet_i = target_i & other index j < target_j
		// until all index have equal ones.
		auto t = target;
		vector<int> m(3, INT_MIN);
		for (auto s: triplets) {
			if (s[0] <= t[0] && s[1] <= t[1] && s[2] <= t[2]) {
				m = {max(s[0], m[0]), max(s[1], m[1]), max(s[2], m[2])};
			}
		}
		return m == t;
	}
};
