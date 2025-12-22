class Solution {
pubilc:
	int findMin(vector<int>& nums) {
		int n = nums.size();
		int ref = nums[0];
		if (n==1) return ref;

		bool circular = nums[n-1] < nums[0];
		if (!circular) return ref;
		ref = nums[n-1];

		int start = 0;
		int end = n-1;
		while(start < end) {
			int mid = (start+end)/2;
			int val = nums[mid];
			if (ref < val) start = mid+1;
			else if (ref > val) {
				end = mid;
				ref = val;
			} else assert(0);
		}
		assert(start == end);
		return ref;
	}
};
