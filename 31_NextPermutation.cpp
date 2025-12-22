// The next value of i must picked from later position
// For i=size-2
//		if next value of nums[i] is before i,
//			--i; and run again
//		else
//			put minium after i; break
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		const int size = nums.size();
		if (size <= 1) return;
		if (size == 2) {
			std::swap(nums.front(), nums.back());
			return;
		}

		// nums[i+1:] is sorted in decreasing order
		// which means nums[i+1:] is the max in their range
		int i = size-2;
		for (; i>=0; --i) {
			if (nums[i] < nums[i+1]) break;
		}
		if (i<0) {
			reverse(nums.begin(), nums.end());
			return;
		}

		// find the next value from i+1 ~ end
		auto eit = nums.rbegin()+ (size-i-1);
		auto it = std::upper_bound(nums.rbegin(), eit, nums[i]);
		assert(it != eit); // atleast n[i+1] > n[i]
		std::swap(*it, nums[i]);

		// Note that array[i+1:] is still sorted
		// Turn decreasing to increasing, which is minimum
		reverse(nums.begin()+i+1, nums.end());
	}
};
