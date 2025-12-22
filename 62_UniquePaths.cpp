class Solution {
public:
	int uniquePaths(int m, int n) {
		int a = max(m,n)-1;
		int b = min(m,n)-1;
		// C(a+b, b)
		long fmn=1;
		long fn=1;
		for (int i=1; i<=b; ++i) {
			fmn *= (a+i);
			// prevent integer overflow
			if (fmn % i == 0) 	fmn /= i;
			else 				fn *= i;
		}
		return fmn/fn;
	}
};
