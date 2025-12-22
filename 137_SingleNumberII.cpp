class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int n1 = 0;
		int n2 = 0;
		for (int v:nums) {
			// bit add
			n2 = n2 ^ (n1 & v);
			n1 = n1 ^ v;
			// mod 3
			int n3 = n1 & n2;
			n1 = n1 ^ n3;
			n2 = n2 ^ n3;
		}
		return n1;
	}
};
