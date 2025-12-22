class Solution {
public:
	vector<vector<int>> ret;
	vector<int> ref;
	void gensubsets(vector<int>& nums, int i) {
		if (i == nums.size()) {
			ret.push_back(ref);
			return;
		}
		gensubsets(nums, i+1);
		ref.push_back(nums[i]);
		gensubsets(nums, i+1);
		ref.pop_back();
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		gensubsets(nums, 0);
		return this->ret;
	}
};
