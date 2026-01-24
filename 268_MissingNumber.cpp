// Time : Beats 100%
// Memory : Beats 13%
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int maxv = -1;
		long sum = 0;
		bool hasZero = false;
		for (int n : nums) {
			sum += n;
			maxv = max(maxv, n);
			if (n==0) hasZero = true;
		}
		if (!hasZero) return 0;
		long ideal_sum = maxv * (maxv+1)/2;
		int ans = ideal_sum - sum;
		if (ans == 0) ans = maxv +1;
		return ans;
	}
};
