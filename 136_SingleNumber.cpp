class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (int v:nums) ret = ret ^ v;
		return ret;
	}
};
