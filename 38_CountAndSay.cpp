class Solution {
public:
	// 1: 1
	// 2: 11
	// 3: 21
	// 4: 1211
	// 5: 111221
	string countAndSay(string s) {
		string ret;
		char last = s[0];
		int count = 1;
		for (int i=1; i<s.size(); ++i) {
			if (s[i] == last) {
				++count;
			} else {
				ret += to_string(count) + last;
				last = s[i];
				count = 1;
			}
		}
		ret += to_string(count) + last;
		return ret;
	}
	string countAndSay(int n) {
		string s = "1";
		for (int i=0;i<n-1;++i) {
			s = countAndSay(s);
		}
		return s;
	}
