// Time : Beats 87.42%
// Memory : Beats 76.49%
class Solution {
public:
	// Binary search
	bool IsCompleteEating(vector<int>& piles, int h, int k) {
		int hsum = 0;
		for (auto p : piles) {
			hsum += p / k;
			if (p%k != 0) hsum += 1; //ceiling
		}
		return hsum <= h;
	}
	int minEatingSpeed(vector<int>& piles, int h) {
		int pmax = INT_MIN;
		int ksum = 0;
		for (auto p : piles) {
			pmax = max(p, pmax);
			ksum += p/h;
		}
		if (piles.size() == h) return pmax;

		int u = pmax;
		int l = max(ksum, 1); // can be simply one
		while (l < u) {
			int mid = (l+u)/2;
			bool val = IsCompleteEating(piles, h, mid);
			if (val) u = mid;
			else l = mid+1;
		}
		assert(l == u);
		return l;
	}
};
