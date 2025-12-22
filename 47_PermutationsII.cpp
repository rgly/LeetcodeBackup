class Solution {
public:
	vector<vector<int>> ret;
	vector<int> remain;
	vector<bool> used;
	vector<int> ref;
	void permuteUniqueImpl(int idx) {
		if (idx == ref.size()-1) {
			auto it = std::find(used.begin(), used.end(), false);
			int ii = std::distance(used.begin(), it);
			ref[idx] = remain[ii];
			ret.push_back(ref);
			return;
		}

		int last;
		for (int i=0; i<ref.size();++i) {
			if (used[i]) continue;
			int v = remain[i];
			if (i != 0 && v == last) continue;
			ref[idx] = v;
			used[i] = true;
			permuteUniqueImpl(idx+1);
			used[i] = false;
			last = v;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		const int size = nums.size();
		sort(nums.begin(), nums.end());
		remain = nums;
		ref.resize(size)
		used.resize(size, false);
		permuteUniqueImpl(0);
		return this->ret;
	}
};
