class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int size = triangle.size();
		if (size == 0) return -1;
		if (size == 1) return triangle[0][0];
		vector<int> buf = triangle.back();
		for (int i=size-2; i>=0; --i) {
			for (int j=0; j<=i; ++j) {
				int subtreemin =  min(buf[j], buf[j+1]);
				buf[j] = triangle[i][j] +subtreemin;
			}
		}
		return buf[0];
	}
};
