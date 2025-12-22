class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		// convert non-positive to 1, also check 1 exist
		// otherwise return 1
		bool hasOne = false;
		for (auto& v:nums) {
			if (v==1) hasOne = true;
			else if (v<=0) v = 1;
		}
		if (!hasOne) return 1;

		// use nums as hash for range 1~nums.size()
		// nums[i-1] = -1 if value i exist
		int v2;
		for (int i=0; i<nums.size();++i) {
			int v = nums[i];
			while (1<=v && v<=nums.size()) {
				v2 = nums[v-1];
				nums[v-1] = -1;
				v = v2;
			}
		}
		// check missing value
		for (int i=0; i<nums.size();++i) {
			if (nums[i] > 0) return i+1;
		}
		return nums.size()+1;
	}
};
