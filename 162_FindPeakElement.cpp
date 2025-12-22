class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		assert(n);
		if (n==1) return 0;
		if (nums[0] > nums[1]) return 0;
		if (nums[n-1] > nums[n-2]) return n-1;

		int start=1;
		int end=n-2;
		while (start<=end) {
			int mid = (start+end)/2;
			int val = nums[mid];
			int lval = nums[mid-1];
			int rval = nums[mid+1];
			if (val > lval && val > rval) return mid;
			else if (lval > rval) end = mid-1;
			else start = mid+1;
			// if (lval == rval) then go left for no reason.
		}
		return -1;
	}
};
