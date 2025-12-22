// Time: Beats 100%
// Memory: Beats 9.06%
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		int lb=0;
		int ub=nums.size()-1;
		while (lb <= ub) {
			int mid = lb + (ub-lb)/2;
			int v = nums[mid];
			if (v == target) return mid;
			else if (v < target) {
				lb = mid+1;
			} else {
				ub = mid-1;
			}
		}
		return -1;
	}
};
