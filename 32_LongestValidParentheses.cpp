// Time: beats 100% 
// Memory: beats 94.32% 
class Solution {
public:
	int longestValidParentheses(string s) {
		int left = 0;
		int right = 0;
		int maxlen = 0;
		for (char c:s) {
			if (c == '(') {
				++left;
			} else {
				++right;
				if (right > left) right=left=0;
				else if (right == left) {
					maxlen = max(maxlen, 2*right);
				}
			}
		}
		right=left=0;
		for (int i=s.size()-1; i>=0; --i) {
			char c = s[i];
			if (c == '(') {
				++left;
				if (right < left) right=left=0;
				else if (right == left) {
					maxlen = max(maxlen, 2*right);
				}
			} else {
				++right;
			}
		}
		return maxlen;
	}
};
