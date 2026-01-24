// Time : Beats 40.18%
// Memory : Beats 89.64%
// already refers to other's DP solution, but top-down DP
// seems slower, better to use bottom-up DP
class Solution {
public:
	vector<vector<int>> cache;
	// return max coin of a range i to j
	// pick the last shot, so the coins are from boundary values.
	// complexity: x^1.5
	int solve(vector<int>& nums, int l, int u) {
		if (l > u) return 0;
		if (l == u) return nums[u-1] * nums[u] * nums[u+1];
		if (cache[l][u] != -1) return cache[l][u];

		int maxv = INT_MIN;
		int boundary_v = nums[l-1] * nums[u+1];
		for (int i=l; i<=u; ++i) {
			int left_v = solve(nums, l, i-1);
			int right_v = solve(nums, i+1, u);
			int v = nums[i] * boundary_v + left_v + right_v;
			maxv = max(maxv, v);
		}
		cache[l][u] = maxv;
		return maxv;
	}

	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		cache.resize(nums.size(), vector<int>(nums.size(), -1));
		return solve(nums, 1, nums.size()-2);
	}
};
