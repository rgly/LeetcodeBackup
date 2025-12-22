// all candidates are unique, and >=2
class Solution {
public:
	vector<vector<int>> results;
	void combination(vector<int>& candidates, int target, int start, int end, vector<int>& ref) {
		if (start == end) return;
		int minval = candidates[start];
		if (target < minval) return;
		else if (target == minval) {
			results.push_back(ref);
			results.back().push_back(minval);
			return;
		}

		// start not chosen
		if (start+1<end) {
			int subminval = candidates[start+1];
			combination(candidates, target-subminval, start+1, end, ref);
		}
		// start chosen
		ref.push_back(minval);
		combination(candidates, target-minval, start, end, ref);
		ref.pop_back();
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> ref;
		combination(candidates, target, 0,
					candidates.size(), ref);
		return results;
	}
};
