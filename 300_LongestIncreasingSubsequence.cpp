class Solution {
public:
	// length of the longest strictly increasing seq
	// complexity nlog(n)
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() <=1) return nums.size();
		// sorted vector n:lengthOfLIS
		vector<int> LIS;
		for (int i=0;i<nums.size();++i) {
			int N = nums[i];
			auto it = lower_bound(LIS.begin(), LIS.end(), N);
			if (it != LIS.end()) *it = N;
			else LIS.push_back(N);
		}
		return LIS.size();
	}
};
