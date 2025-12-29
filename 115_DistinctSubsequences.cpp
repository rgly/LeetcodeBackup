// Time : Beats 89.11%
// Memory : Beats 79.11%
class Solution {
public:
	int numDistinct(string s, string t) {
		if (t.size() > s.size() ) return 0;
		if (t.size() == s.size() ) return s==t;
		// DP[i][j] = DP[i-1][j-1] * match + DP[i-1][j] (skip char)
		vector<int> DP(s.size()+1, 1); // empty is always matched
		for (unsigned int j = 1; j<=t.size(); ++j) {
			unsigned int last=DP[0];
			DP[0] = 0;
			for (unsigned int i = 1; i<=s.size(); ++i) {
				unsigned int DP_i = DP[i-1];
				if (t[j-1] == s[i-1])
					DP_i += last;
				last = DP[i];
				DP[i] = DP_i;
			}
		}
		return DP[s.size()];
	}
};
