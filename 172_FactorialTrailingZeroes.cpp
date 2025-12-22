class Solution {
public:
	int getfactors(int n, int factor) {
		//count how many 5, 25, 125, ... appears
		assert(n>=1);
		int cnt=0;
		const int powerf = log(n)/log(factor);
		for (int i=1;i<=powerf;++i) {
			const int pow_base = pow(factor,i);
			cnt += n/pow_base;
		}
		return cnt;
	}
	int trailingZeroes(int n) {
		if (n==0) return 0;
		// get factors of 2, 5, 10
		int factor5 = getfactors(n, 5);
		int factor2 = getfactors(n, 2);
		int factor10 = min(factor5, factor2);
		return factor10;
	}
};
