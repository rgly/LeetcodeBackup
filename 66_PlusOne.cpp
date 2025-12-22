class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry=1;
		for(int i=digits.size()-1; i>=0; --i) {
			int d = digits[i] + carry;
			carry = (d >= 10)? 1:0;
			if (carry) d -= 10;
			digits[i] = d;
			
			if (!carry) break;
		}
		if (carry) digits.insert(digits.begin(), 1);
		return digits;
	}
};
