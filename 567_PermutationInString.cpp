// Time : Beat 71.70%
// Memory : Beat 67.99%
class Solution {
public:
	// a typical two pointer problem
	bool checkInclusion(string s1, string s2) {
		int n = s1.size();
		if (n==0) return true;
		if (s2.size() < n) return false;
		// only use lower English letters
		array<int, 26> freq;
		fill(freq.begin(), freq.end(), 0);
		for (char c: s1) {
			int id = c - 'a';
			++freq[id];
		}
		array<int, 26> freq2;
		fill(freq2.begin(), freq2.end(), 0);
		for (int i=0; i<n; ++i) {
			int id = s2[i] - 'a';
			++freq2[id];
		}
		if (freq == freq2) return true;
		for (int i=n; i<s2.size(); ++i) {
			int drop_id = s2[i-n] - 'a';
			int add_id = s2[i] - 'a';
			--freq2[drop_id];
			++freq2[add_id];
			if (freq == freq2) return true;
		}
		return false;
	}
};
