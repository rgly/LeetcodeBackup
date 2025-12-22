class Solution {
public:
	vector<int> ref;
	vector<vector<int>> ret;
	void explore(vector<int>& nums, int i) {
		const int n = nums.size();
		if (i==n) {
			ret.push_back(ref);
			return;
		}
		// choose i-th element, jump to i+1
		int v =nums[i]
		ref.push_back(v);
		explore(nums, i+1);
		ref.pop_back();
		// not choose i-th element, jump to next different element
		while (i+1 < n && nums[i+1] == v) {
			++i;
		}
		explore(nums, i+1);
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		const int n = nums.size();
		if (n<=1) return {nums};
		sort(nums.begin(), nums.end());
		explore(nums, 0);
		return this->ret;
	}
};
