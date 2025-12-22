class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		// a 4x4 square = 3x3 left + 3x3 top + 3x3 topleft + 1x1 buttomright
		// m[i][j] = min(m[i-1][j], m[i][j-1], m[i-1][j-1])+1

		int max_len = 0;
		vector<int> buf(n);
		for (int j=0; j<n; ++j) {
			int val = matrix[0][j] - '0';
			buf[j] = val;
			max_len = max(max_len, val);
		}
		int topleft;
		for (int i=1; i<m; ++i) {
			int val = matrix[i][0] - '0';
			topleft = buf[0];
			buf[0] = val;
			max_len = max(max_len, val);
			for (int j=1; j<n; ++j) {
				val = matrix[i][j] - '0';
				int top = buf[j];
				int left = buf[j-1];
				val *= min(top, min(left, topleft))+1;
				buf[j] = val;
				topleft = top;
				max_len = max(max_len, val);
			}
		}
		return max_len*max_len;
	}
};
