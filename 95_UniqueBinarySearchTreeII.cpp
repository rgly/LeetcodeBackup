//Time : Beats 66.85%
//Memory : Beats 23.79%
class Solution {
public:
	vector<TreeNode*> gen(int i, int j) {
		if (i>j) return {};
		vector<TreeNode*> ret;
		for (int a=i; a<=j; ++a) {
			vector<TreeNode*> lefts, rights;
			if (a>i) {
				lefts = gen(i, a-1);
			} else {
				lefts.push_back(nullptr);
			}
			if (a<j) {
				rights = gen(a+1, j);
			} else {
				rights.push_back(nullptr);
			}
			for (auto* l:lefts)
			for (auto* r:rights)
				ret.push_back(new TreeNode(a, l, r));
		}
		return ret;
	}
	vector<TreeNode*> generateTrees(int n) {
		return gen(1,n);
	}
