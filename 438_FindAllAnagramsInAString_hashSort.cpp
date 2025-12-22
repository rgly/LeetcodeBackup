class Solution {
public:
	void getHash(pair<int, int>& h, int plus , int minus) {
		h.first += plus;
		h.first -= minus;
		h.second ^= plus^minus;
	}
	vector<int> findAnagrams(string s, string p) {
		pair<int, int> h1;
		sort(p.begin(), p.end());
		for (char c: p) {
			getHash(h1, int(c), 0);
		}
		vector<int> ret;
		pair<int, int> h2;
		for (int i=0; i<p.size(); ++i) {
			getHash(h2, s[i], 0);
		}
		if (h1 == h2) {
			string s1 = s.substr(0, p.size());
			sort(s1.begin(), s1.end());
			if (s1 == p) ret.push_back(0);
		}
		for (int i=p.size(); i<s.size(); ++i) {
			int idx = i-p.size()+1;
			getHash(h2, s[i], s[idx-1]);
			if (h1 == h2) {
				string s1 = s.substr(idx, p.size());
				sort(s1.begin(), s1.end());
				if (s1 == p) ret.push_back(idx);
			}
		}
		return ret;
	}
}
