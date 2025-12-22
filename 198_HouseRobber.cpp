class Solution {
public:
	int rob(vector<int>& nums) {
		int size = nums.size();
		if (size ==1) return nums[0];
		int d2 = nums[0];
		int d1 = max(nums[0], nums[1]);
		//D[n] = max(nums[n]+D[n-2], D[n-1])
		for (int i=2;i<size;++i){
			int tmp = max(nums[i]+d2, d1);
			d2 = d1;
			d1 = tmp;
		}
		return d1;
	}
};
