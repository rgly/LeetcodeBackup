class Solution {
public:
	float mysqrt(int n) {
		assert(n > 0);
		// Newton method
		// find root of y = x^2-n
		// x1 = x0- y0/y'0
		// x0 = n
		float x = n;
		float x_last = 0;
		float y, y_d;
		while (abs(x - x_last) > 0.1) {
			y = x*x-n;
			y_d = 2*x;
			x_last = x;
			x = x - y/y_d;
		}
		return x;
	}
	int mySqrt(int x) {
		assert(x>=0);
		if (x <= 1) return x;
		long i = std::round(mysqrt(x));
		// This question ask to round down
		// Due accuracy concern, verify in integer
		while (i*i> x) --i;
		return i;
	}
};
