class Solution {
public:
	// n[i] + comb(n[i+1:], target-n[i])  and 
	// comb(n[i+1:], target)
	vector<vector<int>> ret;
	vector<int> ref;

	void combine(vector<int>& candidates, int target, int idx) {
		if (target == 0) ret.push_back(ref);
		if (target < 0 || idx == candidates.size()) return;

		int val = candidates[idx];
		// bacaused it is sorted, not possible for later vals
		if (target < val) return;
		if (val <= target) {
			ref.push_back(val);
			combine(candidates, target-val, idx+1);
			ref.pop_back();
		}

		// Once give up the value, skip all element with same value.
		while (idx+1 < candidates.size() && candidates[idx+1] == val) {
			++idx;
		}
		combine(candidates, target, idx+1);
			
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		combine(candidates, target, 0);
		return this->ret;
	}
};
