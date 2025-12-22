// graphic algorithm explaination
// http://manacher-viz.s3-website-us-east-1.amazonaws.com/#/
class Solution {
public:
	void ExpandAroundCenter(string s, vector<int>& p,
							int i, int offset) {
		while (s[i-offset] == s[i+offset]) {
			++offset;
		}
		p[i] = offset-1;
	}

	// Manacher algorithm
	string longestPalindrome(string s) {
		// # is used for abba case
		// like #a#b#b#a#
		//    P  1014101
		string ss = "$#";
		for (char c:s) {
			ss.push_back(c);
			ss.push_back('#');
		}
		// head and tail notation used to force unequal
		// to skip 0<=i<size() check natually.
		ss.push_back('^');

		vector<int> p(ss.size());
		int radius_end=0;
		int center=0;
		int maxlength = 0;
		int maxcenter = 0;
		for (int i=1;i<ss.size()-1;++i) {
			int mirror = 2*center-i;
			if (i < radius_end) {
				// skip check if palindromic radius covers,
				// which means I have checked it.
				if (i+p[mirror] < radius_end) {
					p[i] = p[mirror];
				} else {
					ExpandAroundCenter(ss, p, i, radius_end-i);
				}
			} else {
				// tranditional Expand Around Center
				ExpandAroundCenter(ss, p, i, 1);
			}
			int plen = p[i];
			if (i+plen > radius_end) {
				radius_end = i+plen;
				center = i;
			}
			if (plen > maxlength) {
				maxlength = plen;
				maxcenter = i;
			}
		}
		int ss_start_pos = maxcenter-maxlength+1;
		int s_start_pos = (ss_start_pos-2)/2;
		string rets = s.substr(s_start_pos, maxlength);
		return rets;
	}
};
