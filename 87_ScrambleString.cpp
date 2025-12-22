// Time: Beat 85.74%
// memory: Beat 57.81%
// complexity: N^2
// Because s1.len <=30, prefix xor optimization for better
// complexity is useless
class PrefixHashTy {
public:
	vector<int> prexor;
	void fill(string::iterator it, string::iterator eit) {
		if (it == eit) return;
		int val = *it;
		prexor.push_back(val);
		++it;
		while (it != eit) {
			val ^= *it;
			prexor.push_back(val);
			++it;
		}
	}
	int get(int start, int end) {
		assert(0 <= start
				&& start <= end
				&& end < prexor.size());
		int val = prexor[end];
		if (start > 0) {
			val ^= prexor[start-1];
		}
		return val;
	}
};
class Solution {
public:
	PrefixHashTy s1hash;
	PrefixHashTy s2hash;
	vector<vector<vector<int>>> cache;

	// compare the hashed charcter count of s1 to
	// forward or reversed s2 by arbitary subset
	bool isScramble(int i11, int i12, int i21, int i22) {
		assert(i11 <= i12);
		assert(i21 <= i22);
		const int n = i12-i11+1;
		assert(n == i22-i21+1);
		assert(n > 0);
		bool ret = false;
		if (cache[i11][i21][n-1] >= 0)
			return cache[i11][i21][n-1];
		if (n==1) {
			ret = s1hash.get(i11, i11) == s2hash.get(i21, i21);
			cache[i11][i21][n-1] = ret;
			return ret;
		}
		for (int i=0; i<n-1; ++i) {
			auto h1 = s1hash.get(i11, i11+i);
			auto h2 = s2hash.get(i21, i21+i);
			if (h1 == h2
				&& isScramble(i11, i11+i, i21, i21+i)
				&& isScramble(i11+i+1, i12, i21+i+1, i22)) {
					ret = true;
					break;
			}

			auto h2r = s2hash.get(i22-i, i22);
			if (h1 == h2r
				&& isScramble(i11, i11+i, i22-i, i22)
				&& isScramble(i11+i+1, i12, i21, i22-i-1)) {
					ret = true;
					break;
			}
		}
		cache[i11][i21][n-1] = ret;
		return ret;
	}

	bool isScramble(string s1, string s2) {
		const int n = s1.size();
		if (n != s2.size()) return false;
		if (s1 == s2) return true;
		s1hash.fill(s1.begin(), s1.end());
		s2hash.fill(s2.begin(), s2.end());

		if (s2hash.get(0, n-1) != s1hash.get(0, n-1)) {
			return false;
		}
		cache.resize(n,
					vector<vector<int>>(n,
					vector<int>(n, -1)));
		return isScramble(0, n-1, 0, n-1);
	}
};
