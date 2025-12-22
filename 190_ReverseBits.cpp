class Solution {
public:
	int reverseBits(int n) {
		int max_bit = 1 << 31;
		int lsb = 1;
		assert((n & 1) == 0);
		int msb = max_bit;
		int ret = 0;
		while (lsb != max_bit) {
			lsb = lsb << 1;
			msb = (msb >> 1) & (~max_bit);
			cond = n & lsb;
			if (cond !=0) ret |= msb;
		}
		return ret;
	}
};
