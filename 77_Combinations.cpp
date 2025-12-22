// Given two integers n and k, return all
// possible combinations of k numbers chosen
// from the range [1, n].

Class Solution {
public:
	vector<vector<int>> combine(int m, int n, int k,
		vector<int>& prefix) {
		assert(n>=m);
		int range = n-m+1;
		int size = prefix.size();
		if (k == range) {
			vector<vector<int>> ret(1, prefix);
			for (int i=0;i<range;++i) ret[0][size-k+i]=m+i;
			return ret;
		} else if (k == 1) {
			vector<vector<int>> ret(range, prefix);
			for (int i=0;i<range;++i) ret[i].back() = m+i;
			return ret;
		}

		// m not choosen
		auto v1 = combine(m+1, n, k, prefix);
		// m choosen
		prefix[size-k] = m;
		auto v2 = combine(m+1, n, k-1, prefix);
		v1.insert(v1.end(), v2.begin(), v2.end());
		return v1;
	}
	vector<vector<int>> combine(int n, int k) {
		vector<int> ref(k);
	 	return combine(1, n, k, ref);
	}
};
