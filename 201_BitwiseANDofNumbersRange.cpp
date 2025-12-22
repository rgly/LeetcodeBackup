class Solution {
public:
	int getMSB(int n) {
		if (n < 0) return 31;
		else if (n == 0) return -1;
		else if (n == 1) return 0;
		int i = 0;
		while (n != 1) {
			n = (n >> 1);
			++i;
		}
		return i;
	}
	int rangeBitwiseAnd(int left, int right) {
		int ret=0;
		while (left!=0 && right!=0) {
			int l = getMSB(left);
			int r = getMSB(right);
			if (r != l) return ret;
			int bit = 1<<l;
			ret |= bit;
			left &= ~bit;
			right &= ~bit;
		}
		return ret;
	}
};
