class Solution {
public:
	bool search(vector<int>& nums, int target, int lb, int ub) {
		if (lb > ub) return false;
		int base = nums[lb];
		if (lb == ub) return base == target;
		bool right = target >= base;
		while (lb <= ub) {
			int mid = (lb+ub)/2;
			int midval = nums[mid];
			if (midval == target) {
				return true;
			} else if (midval == base) {
				bool result1 = search(nums, target, lb, mid-1);
				bool result2 = search(nums, target, mid+1, ub);
				return result1 | result2;
			} else if (base < midval) {
				if (midval < target | !right) {
					lb = mid+1;
				} else {
					ub = mid-1;
				}
			} else {
				if (midval > target | right) {
					ub = mid-1;
				} else {
					lb = mid+1;
				}
			}
		}
		return false;
	}
	bool search(vector<int>& nums, int target) {
		return search(nums, target, 0, nums.size()-1);
	}
};
