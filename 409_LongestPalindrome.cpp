// Time : Beats 100%
// Memory : Beats 36.65%
class Solution {
public:
	int longestPalindrome(string s) {
		// Count
		unordered_map<char, int> cnt;
		for (char c:s) {
			if (cnt.count(c) == 0) cnt[c] =1;
			else ++cnt[c];
		}
		// All even numbers are valid
		// And only even parts of odd numbers
		// if odd numbers, length += 1
		int length = 0;
		bool hasodd = false;
		for(auto [c, count]: cnt) {
			if (count %2 == 0) {
				length += count;
			} else {
				length += count-1;
				hasodd = true;
			}
		}
		if (hasodd) length += 1;
		return length;
	}
};
