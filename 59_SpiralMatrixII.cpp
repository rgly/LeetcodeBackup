class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (n==0) return {{}};
		if (n==1) return {{1}};
		vector<vector<int>> ret(n, vector<int>(n));
		int i=1;
		int u, l, r, b;
		u=l=0;
		r=b=n;
		while(u<b && l<r) {
			for(int j=l; j<r; ++j) {
				ret[u][j] = i;
				++i;
			}
			++u;
			if (u==b) break;

			for(int j=u; j<b; ++j) {
				ret[j][r-1] = i;
				++i;
			}
			--r;
			if (l==r) break;

			for(int j=r-1; j>=l; --j) {
				ret[b-1][j] = i;
				++i;
			}
			--b;
			if (u==b) break;

			for(int j=b-1; j>=u; --j) {
				ret[j][l] = i;
				++i;
			}
			++l;
		}
		return ret;
	}
};
