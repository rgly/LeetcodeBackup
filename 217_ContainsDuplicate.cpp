// Time : Beats 46.80%
// Memory : Beats 59.98%
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> used;
		for (int n: nums) {
			if (used.count(n) ==1) return true;
			used.insert(n);
		}
		return false;
	}
};
