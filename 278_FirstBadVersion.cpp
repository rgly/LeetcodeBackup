// Time: Beat 100%
// Memory: Beat 69.71%
class Solution {
public:
	int firstBadVersion(int n) {
		// use bool isBadVersion(int version)
		// binary search
		if (n==1) return int(isBadVersion(1));
		if (!isBadVersion(n)) return n+1;
		int lb = 1;
		int ub = n;
		while (lb < ub) {
			int mid = lb+(ub-lb)/2;
			bool f = isBadVersion(mid);
			if (f) {
				ub = mid;
			} else {
				lb = mid+1;
			}
		}
		return lb;
	}
};
