// Time : Beats 100%
// Memory : Beats 26.59%
class Solution {
public:
	// * is wildcard for (, ), or nothing
	bool checkValidString(string s) {
		int leftmax = 0;
		int leftmin = 0;
		for (char c: s) {
			if (c == '(') {
				++leftmax;
				++leftmin;
			} else if (c == ')') {
				--leftmax;
				--leftmin;
			} else {
				++leftmax;
				--leftmin;
			}
			if (leftmax < 0) return false;
			leftmin = max(leftmin, 0)
		}
		return leftmin == 0;
	}
};
