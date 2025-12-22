//Time : Beats 100%
//Memory : Beats 97.93%
class Solution {
public:
	// cache[i][j] keeps result of gen(i,j)
	// to share the duplicated subtree
	vector<vector<vector<TreeNode*>>> cache;
	vector<TreeNode*> gen(int i, int j) {
		if (!cache[i-1][j-1].empty()) {
			return cache[i-1][j-1];
		}
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
		cache[i-1][j-1] = ret;
		return ret;
	}
	vector<TreeNode*> generateTrees(int n) {
		cache.resize(n, vector<vector<TreeNode*>>(n));
		return gen(1,n);
	}
