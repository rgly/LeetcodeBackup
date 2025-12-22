class Solution {
public:
	bool IsDigit(char c) {
		return '0' <= c & c <= '9';
	}
	bool isNumber(string s) {
		if (s.empty()) return false;
		int e_count=0;
		int sign_count=0;
		int dot_count=0;
		bool IsValue=false;
		bool IsStart=true;
		for (int i=0; i<s.size(); ++i) {
			char c = s[i];
			if (c == 'e' | c == 'E') {
				if (e_count >=1) return false;
				if (!IsValue) return false;
				++e_count;
				sign_count=0;
				dot_count=0;
				IsValue = false;
				IsStart = true;
			} else if (c=='.') {
				if (e_count) return false;
				++dot_count;
			} else if (c=='-' || c=='+') {
				if (!IsStart) return false;
				if (IsValue) return false;
				++sign_count;
			} else if (IsDigit(c)) {
				IsValue=true;
			} else {
				return false;
			}
			if (e_count >1) return false;
			if (sign_count >1) return false;
			if (dot_count >1) return false;
			if (c != 'e' && c != 'E') { IsStart = false;}
		}
		if (!IsValue) return false;
		return true;
	}
};
