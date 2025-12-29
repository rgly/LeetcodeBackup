// Time : Beats 100%
// Memory : Beats 23.82%
class Solution {
public:
	// Kadane algorithm with keep localmax and localmin
	int maxProduct(vector<int>& nums) {
		const int n = nums.size();
		if (n == 0) return 0;
		int v = nums[0];
		int localmax = v;
		int globalmax = v;
		int localmin = v;
		for (int i=1; i<n; ++i) {
			v = nums[i];
			int tmp_localmax = max(localmax*v , max(localmin*v, v));
			localmin = min(localmin*v , min(localmax*v, v));
			localmax = tmp_localmax;
			globalmax = max(localmax , globalmax);
		}
		return globalmax;
	}
};
