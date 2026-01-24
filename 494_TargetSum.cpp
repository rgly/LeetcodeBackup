// Time : Beat 100%
// Memory : Beat 68.58%
class Solution {
public:
	// sum(P) - sum(N) = target
	// sum(P) - sum(N) + sum(P) + sum(N) = target + sum(nums)
	// 2sum(P) = target + sum(nums)
	// sum(P) = (target + sum(nums))/2
	int findTargetSumWays(vector<int>& nums, int target) {
		const int n = nums.size();
		if (n==0) return 0;

		target = abs(target);
		int sum = 0;
		for (int i=0; i<n; ++i) {
			nums[i] = abs(nums[i]);
			sum += nums[i];
		}
		if ((target + sum)%2 == 1) return 0;
		target = (target + sum)/2;

		vector<int> DP(target+1);
		DP[0] = 1;

		// DP[target][firstNnums] = DP[target][firstNnums-1] + DP[target-num[i]][firstNnums-1]
		// If using first n numbers
		for (int num: nums) {
			// reversely computed so that not to break the rule of first n numbers.
			for (int j=target; j>=num; --j) {
				DP[j] += DP[j - num];
			}
		}
		return DP[target];
	}
};
