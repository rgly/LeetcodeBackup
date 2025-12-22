// Time: Beat 91.16%
// Memory: Beat 38.85%
class Solution {
public:
	vector<vector<int>> cache;
	bool dfs(vector<int>& nums, int i, int target) {
		if (target == 0) return true;
		if (i == nums.size()) return false;
		if (cache[i][target-1] >= 0)
			return cache[i][target-1];
		int v = nums[i];
		if (target < v) {
			cache[i][target-1] = 0;
			return false;
		}
		// chosen
		if ( dfs(nums, i+1, target-v) ) {
			cache[i][target-1] = 1;
			return true;
		}
		// not chosen
		bool b = dfs(nums, i+1, target);
		cache[i][target-1] = int(b);
		return b;
	}
	bool canPartition(vector<int>& nums) {
		const int n = nums.size();
		sort(nums.begin(), nums.end());

		int sum=0;
		for (int v:nums) sum += v;
		if (sum%2 == 1) return false;

		int target = sum/2;
		cache.resize(n, vector<int>(target, -1));
		return dfs(nums, 0, target);
	}
};
