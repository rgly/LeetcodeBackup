// Time : Beats 22.22%
// Memory : Beats 54.44%
class Solution {
public:
	vector<int> countBits(int n) {
		vector<int> B(n+1);
		B[0] = 0;
		int i=1;
		while (i <= n) {
			for (int j=i; j<min(n+1, 2*j); ++j) {
				B[j] = B[j-i]+1;
			}
			i *= 2;
		}
		return B;
	}
};
