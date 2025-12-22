class Solution {
public:
	vector<bool> cols;
	vector<bool> dias;
	vector<bool> rdias;
	vector<vector<string>> ret;
	vector<int> Qpos;
	void genQueenStr(int n) {
		assert(Qpos.size() == n);
		vector<string> sol(n, string(n, '.'));
		for (int i=0; i<Qpos.size(); ++i) {
			sol[i][Qpos[i]] = 'Q';
		}
		ret.push_back(sol);
	}

	void backtrace(int n, int i) {
		for (int j=0; j<n; ++j) {
			bool conflict = cols[j] | dias[i+j] | rdias[i+n-1-j];
			if (conflict) continue;

			cols[j] = true;
			dias[i+j] = true;
			rdias[i+n-1-j] = true;
			Qpos.push_back(j);

			if (i<n-1) backtrace(n, i+1);
			else genQueenStr(n);

			Qpos.pop_back();
			cols[j] = false;
			dias[i+j] = false;
			rdias[i+n-1-j] = false;
		}
	}

	vector<vector<string>> solveNQueens(int n) {
		cols.resize(n, false);
		dias.resize(2*n-1, false);
		rdias.resize(2*n-1, false);
		backtrace(n, 0);
		return this->ret;
	}
};
