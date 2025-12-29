// Time : Beats 27.61%
// Memory : Beats 39.31%
class Solution {
public:
	// use Deque to store window values, but poped if
	// later value > former values
	void removesmall(deque<int>& window, int val) {
		while (!window.empty() && window.back() < val) {
			window.pop_back();
		}
	}
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		const int n = nums.size();
		if (n==0 || k==0) return {};
		vector<int> ret;
		deque<int> window;
		for (int i=0; i<min(n, k); ++i) {
			removesmall(window, nums[i]);
			window.push_back(nums[i]);
		}
		ret.push_back(window.front());
		if (n<=k) return ret;
		for (int i=k; i<n; ++i) {
			int kick_val = nums[i-k];
			int new_val = nums[i];
			if (window.front() == kick_val) {
				window.pop_front();
			}
			removesmall(window, new_val);
			window.push_back(new_val);
			ret.push_back(window.front());
		}
		return ret;
	}
};
