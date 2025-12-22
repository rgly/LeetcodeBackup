class Solution {
public:
	int maxSubArraySumCircular(vector<int>& nums) {
		assert(!nums.empty());
		if (nums.size() == 1) return nums[0];
		int n = nums.size();
		int sum = nums[0];
		// normal kadene algorithm of maxending
		int res = nums[0];
		int maxending = nums[0];
		for (int i=1;i< n; ++i) {
			int v = nums[i];
			sum += v;
			maxending = max(maxending+v, v);
			res = max(res, maxending);
		}

		// find min ending in middle
		// all group - middle minending == circular
		int negres = nums[1];
		int minending = nums[1];

		// minending
		for (int i=2;i< n-1; ++i) {
			int v = nums[i];
			minending = min(minending+v, v);
			negres = min(negres, minending);
		}
		int circular = sum-negres;
		return max(res, circular);
	}
};
