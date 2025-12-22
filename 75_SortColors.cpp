class Solution {
public:
	// sort 0s,1s,2s in-place in one-pass with O(1) memory.
	void countsort(vector<int>& nums) {
		array<int,3> counter = {0,0,0};
		for (auto v:nums) ++counter[v];
		int last=0;
		for(int z=0;z<3;++z) {
			for(int i=0; i<counter[z];++i) {
				nums[last+i]=z;
			}
			last += counter[z];
		}
	}
	void sortColors(vector<int>& nums) {
		countsort(nums);
	}
};
