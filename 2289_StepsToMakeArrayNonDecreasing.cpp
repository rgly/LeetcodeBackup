// Runtime beats 59.07%
// Memory beats 99.16%
class StackAttr {
public:
	StackAttr(int a, int b): val(a), step(b) {}
	int val;
	int step;
};
class Solution {
public:
	int totalSteps(vector<int>& nums) {
		const int size = nums.size();
		if (size <=1) return 0;
		int maxop=0;
		// value, i-th step to remove
		stack<StackAttr> st;
		for(int i=0; i<size; ++i) {
			int step = 0;
			int n = nums[i];
			
			// pop all the stack <=n, since they don't
			// affect later numbers
			while (!st.empty() && st.top().val <= n) {
				step = max(step, st.top().step);
				st.pop();
			}

			if (st.empty()) {
				st.push({n, 0});
			} else {
				// must have something x > n, since I poped
				// all x <= n
				step += 1;
				// direct decreasing function
				if (step == st.top().step) {
					st.top().val = n;
				} else {
					st.push({n, step});
				}
				maxop = max(maxop, step);
			}
		}
		return maxop;
	}
