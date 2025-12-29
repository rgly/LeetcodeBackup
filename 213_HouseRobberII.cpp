// Time : Beat 100%
// Memory : Beat 97.01%
class Solution {
public:
	// No rob two adjacent houses in a circular arrangement.
	// max(rob house 0, not rob house 0) to break circular dependency
	int tranditional_rob(vector<int>& nums, int start, int end) {
		int size = end-start+1;
		if (size == 0) return 0;
		if (size == 1) return nums[start];
		int last = nums[start];
		int cur = max(nums[start+1], last);
		for (int i=start+2; i<=end; ++i) {
			int pick = nums[i] + last;
			last = cur;
			cur = max(cur, pick);
		}
		return cur;
	}
	int rob(vector<int>& nums) {
		const int size = nums.size();
		if (size == 0) return 0;
		if (size == 1) return nums[0];
		if (size == 2) return max(nums[0], nums[1]);
		int rob_house0 = nums[0] + tranditional_rob(nums, 2, size-2);
		int not_rob_house0 = tranditional_rob(nums, 1, size-1);
		return max(rob_house0, not_rob_house0);
	}
};
