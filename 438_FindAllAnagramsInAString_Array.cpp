// Time : Beats 50.63%
// Memory : Beats 62.08%
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		std::array<int, 26> freq1;
		std::fill(freq1.begin(), freq1.end(), 0);
		for (char c: p) {
			int idx = c-'a';
			++freq1[idx];
		}
		vector<int> ret;
		std::array<int, 26> freq2;
		std::fill(freq2.begin(), freq2.end(), 0);
		for (int i=0; i<p.size(); ++i) {
			int idx = s[i]-'a';
			++freq2[idx];
		}
		if (freq1 == freq2) {
			ret.push_back(0);
		}
		for (int i=p.size(); i<s.size(); ++i) {
			int idx = i-p.size()+1;
			int idx1 = s[i]-'a';
			int idx2 = s[idx-1]-'a';
			++freq2[idx1];
			--freq2[idx2];
			if (freq1 == freq2) {
				ret.push_back(idx);
			}
		}
		return ret;
	}
}
