class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		// this heap.top is the minimal
		priority_queue<int, vector<int>, greater<int>> heap;
		assert(nums.size() >= k);

		for (int i=0; i<k;++i) heap.push(nums[i]);
		int heapmin = heap.top();

		for (int i=k; i<nums.size();++i) {
			int n = nums[i];
			if (n>heapmin) {
				heap.push(n);
				heap.pop();
				heapmin = heap.top();
			}
		}
		return heapmin;
	}
};
