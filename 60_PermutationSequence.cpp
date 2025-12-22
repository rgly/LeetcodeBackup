class Solution {
public:
	// n=3, k=1: "123"
	// n=3, k=3: "213"
	int factorial(int n) {
		int ret =1;
		for (int i=2;i<=n;++i) ret *= i;
		return ret;
	}
	string getPermutation(int n, int k) {
		if (n==0) return "";
		if (n==1) return "1";
		k -=1;
		vector<int> s(n);
		std::iota(s.begin(), s.end(), 1);

		string ret;
		for(int i=1; i<=n; ++i) {
			int f = factorial(n-i);
			int idx = k / f;
			k = k % f;
			char c = '0'+s[idx];
			s.erase(s.begin()+idx);
			ret.push_back(c);
		}
		return ret;
	}
};
