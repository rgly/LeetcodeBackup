// Time : Beats 100%
// Memory : Beats 40.18%
class Solution {
public:
	// index sort to i == nums[i]
	// if nums[nums[i]] == num[i], which means i is occupied
	int findDuplicate(vector<int>& nums) {
		assert(nums.size() >= 2);
		int i = 0;
		while (i < nums.size()) {
			int num = nums[i];
			assert(num < nums.size());
			assert(num >= 0);
			if (num == i) {
				++i;
			} else if (num == nums[num]) {
				// duplicate
				return num;
			} else {
				nums[i] = nums[num];
				nums[num] = num;
			}
		}
		assert(0);
		return 0;
	}
};
