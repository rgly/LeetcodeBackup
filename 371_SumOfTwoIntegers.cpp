// Time: Beats 100%
// Memory: Beats 65.06%
class Solution {
public:
	// implement + without using builtin +
	int getSum(int a, int b) {
		int carry = b;
		for (int i=0; i<32; ++i) {
			int psum = a ^ carry;
			carry = (a & carry) << 1;
			a = psum;
		}
		return a;
	}
};
