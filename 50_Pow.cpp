class Solution {
public:
	int getMSB(int n) {
		if (n < 0) return 31;
		else if (n == 0) return -1;
		else if (n == 1) return 0;
		int i = 0;
		while (n != 1) {
			n = (n >> 1);
			++i;
		}
		return i;
	}
	// x^n
	double myPow(double x, int n) {
		if (x==0) return 0;
		if (n==0 || x==1) return 1;
		if (n==INT_MIN) { // -2^31
			double y = 1/x;
			for (int i=0;i<31;++i) y *= y;
			return y;
		}
		if (n<0) {
			x = 1/x;
			n = -n;
		}
		int msb = getMSB(n);
		double y = x;
		while (msb > 0) {
			y *= y;
			if (n & (1<<(msb-1))) y *= x;
			--msb;
		}
		return y;
	}
};
