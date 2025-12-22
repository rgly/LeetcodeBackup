class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target){
		int m = matrix.size();
		if (m ==0) return false;
		int n = matrix.front().size();
		if (n ==0) return false;
		int size = m*n;

		int start = 0;
		int end = size-1;
		while (start <= end) {
			int mid = (start+end)/2;
			int val = matrix[mid/n][mid%n];
			if (val == target) return true;
			else if (val < target) start = mid+1;
			else end = mid-1;
		}
		return false;
	}
};
