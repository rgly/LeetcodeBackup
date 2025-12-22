class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		// use mental 2D bool array of i(s1 pointer),
		// and j(s2 pointer) to indicate whether i+j s3
		// works.
		// Interleave[i][j] =
		//		(Interleave[i-1][j] & s1[i-1] == s3[i+j-1])
		//		| (Interleave[i][j-1] & s2[j-1] == s3[i+j-1])
		// To save memory, I use 1D buf to record Interleave
		// return Interleave[m-1][n-1]

		// length check
		const int m = s1.size();
		const int n = s2.size();
		if (s3.size() != m+n) return false;
		if (m == 0) return s2==s3;
		if (n == 0) return s1==s3;

		// Since this is a linear complexity problem
		// I don't need to check word count before

		vector<bool> Interleave(n+1);
		// i==0
		Interleave[0] = true;
		for (int j=1; j<=n; ++j) {
			bool match = s2[j-1] == s3[j-1];
			Interleave[j] = Interleave[j-1] & match;
		}
		for (int i=1; i<=m; ++i) {
			// j==0
			bool top = Interleave[0];
			bool topmatch = s1[i-1] == s3[i-1];
			Interleave[0] = top & topmatch;
			// j>0
			for (int j=1; j<=n; ++j) {
				topmatch = s1[i-1] == s3[i+j-1];
				top = Interleave[j];
				bool leftmatch = s2[j-1] == s3[i+j-1];
				bool left = Interleave[j-1];
				Interleave[j] = (top & topmatch) | (left & leftmatch);
			}
		}
		return Interleave[n];
	}
};
