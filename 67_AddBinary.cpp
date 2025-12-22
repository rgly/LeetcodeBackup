class Solution {
public:
	string addBinary(string a, string b) {
		auto i = a.rbegin();
		auto ie = a.rend();
		auto j = b.rbegin();
		auto je = b.rend();
		int carry=0;
		string ret;
		while (i != ie && j != je) {
			int n1 = (*i=='1')? 1:0;
			int n2 = (*j=='1')? 1:0;
			int n = n1+n2+carry;
			carry = (n >= 2)? 1:0;
			n -= carry*2;
			char ns = (n==1) ? '1' : '0';
			ret.push_back(ns);
			++i;
			++j;
		}
		auto k = (i!=ie) ? i : j;
		auto ke = (i!=ie) ? ie : je;
		while (k != ke) {
			int n1 = (*k=='1')? 1:0;
			int n = n1+carry;
			carry = (n >= 2)? 1:0;
			n -= carry*2;
			char ns = (n==1) ? '1' : '0';
			ret.push_back(ns);
			++k;
		}
		if (carry) ret.push_back('1');
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
