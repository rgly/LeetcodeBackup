// Time : Beats 98.47%
// Memory : Beats 98.96%
class Solution {
public:
	// DP[i][j] = max(DP[i-1][j], DP[i][j-1],
		(DP[i-1][j-1]+1)*int(T1[i] == T2[j])  )
	int longestCommonSubsequence(string text1, string text2) {
		// fast check if character is not same
		vector<bool> a1(26, false);
		vector<bool> a2(26, false);
		const int aidx = static_cast<int>('a');
		for (char c : text1) {
			int idx = static_cast<int>(c) - aidx;
			a1[idx] = true;
		}
		for (char c : text2) {
			int idx = static_cast<int>(c) - aidx;
			a2[idx] = true;
		}
		bool IsOverlap = false;
		for (int i=0; i<26; ++i) {
			IsOverlap |= a1[i] & a2[i];
		}
		if (!IsOverlap) return 0;

		// Real 2D DP
		int size1 = text1.size();
		int size2 = text2.size();
		vector<int> DP(size1+1, 0);
		for (int i=1; i<=size2; ++i) {
			int lefttop = DP[0];
			for (int j=1; j<=size1; ++j) {
				int lcs = max(DP[j], DP[j-1]);
				if (text1[j-1] == text2[i-1]) {
					lcs = max(lcs, lefttop+1);
				}
				lefttop = DP[j];
				DP[j] = lcs;
			}
		}
		return DP.back();
	}
};
