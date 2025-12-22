class Solution {
public:
	int hammingWeight(int n) {
		int max_bit = 1<<31;
		int cnt = 0;
		for (int i=0;i<32;++i) {
			int bit = n & 1;
			cnt += bit;
			n = n>>1;
		}
		return cnt;
	}
};
