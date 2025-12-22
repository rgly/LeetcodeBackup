class Solution {
public:
	typedef vector<bool> bvec;
	int queen(int n, int i, bvec& col, bvec& diag, bvec& rdiag) {
		if (i==n) return 1;
		int sum = 0;
		for (int j=0;j<n;++j) {
			int cid = j;
			int did = j-i + (n-1);
			int rid = j+i;
			if (col[cid] | diag[did] | rdiag[rid]) continue;
			col[cid] = diag[did] = rdiag[rid] = true;
			int num = queen(n, i+1, col, diag, rdiag);
			sum += num;
			col[cid] = diag[did] = rdiag[rid] = false;
		}
		return sum;
	}
	int totalNQueens(int n) {
		bvec col(n, false);
		bvec diag(n*2-1, false);
		bvec rdiag(n*2-1, false);
		int ret = queen(n, 0, col, diag, rdiag);
		return ret;
	}
}
