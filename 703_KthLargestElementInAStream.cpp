// Time : Beats 89.83%
// Memory : Beats 24.37%
class KthLargest {
public:
	priority_queue<int, vector<int>, greater<int>> minheap;
	KthLargest(int k, vector<int>& nums) {
		for (int n : nums) {
			minheap.push(n);
		}
		if (k > nums.size()) {
			minheap.push(INT_MIN);
		}
		while (minheap.size() > k) {
			minheap.pop();
		} 
	}
	int add(int val) {
		if (val > minheap.top()) {
			minheap.push(val);
			minheap.pop();
		}
		return minheap.top();
	}
};
