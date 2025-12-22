// Time: Beat 100%
// Memory: Beat 96.10%
class Solution {
public:
	int IsOneDigit(char c0) {
		return c0 != '0';
	}
	int IsTwoDigit(char c0, char c1) {
		if (c0 == '1') return 1;
		else if (c0 == '2' && c1 <= '6') return 1;
		else return 0;
	}
	// use DP of s.size() to solve
	// DP[i] = onedigit & DP[i-1] + twodigit & DP[i-2]
	int numDecodings(string s) {
		if (s.empty()) return 0;
		const int n = s.size();
		if (s.front() == '0') return 0;
		if (n == 1) return 1;

		int last = 1;
		int cur = IsOneDigit(s[1]) * last
				+ IsTwoDigit(s[0], s[1]);
		for (int i=2; i<n; ++i) {
			int next = IsOneDigit(s[i]) * cur
						+ IsTwoDigit(s[i-1], s[i]) * last;
			last = cur;
			cur = next;
		}
		return cur;
	}
};
