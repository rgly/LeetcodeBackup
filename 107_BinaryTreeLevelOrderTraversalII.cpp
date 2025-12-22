class Solution {
public:
	vector<vector<int>> ret;
	// all subtree only used once, no need to buffer
	void traverse(TreeNode* root, int idx) {
		if (!root) return;
		int v = root->val;
		if (ret.size() == idx) {
			ret.push_back({v});
		} else {
			ret[idx].push_back(v);
		}
		traverse(root->left, idx+1);
		traverse(root->right, idx+1);
	}
	vector<vector<int>> levelOrderBotom(TreeNode* root) {
		traverse(root, 0);
		reverse(ret.begin(), ret.end());
		return this->ret;
	}
};
