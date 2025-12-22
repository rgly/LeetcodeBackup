class Solution {
public:
	int climbStairs(int n) {
		assert(n>=0);
		if (n<=2) return n;
		int last = 1;
		int cur = 2;
		for (int i=3;i<=n;++i) {
			int tmp = cur + last;
			last = cur;
			cur = tmp;
		}
		return cur;
	}
};
