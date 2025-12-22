// Time : Beats 100%
// Memory : Beats 6.85%
class Solution {
public:
	vector<vector<int>> levelOrderBotom(TreeNode* root) {
		vector<vector<int>> ret;
		if (!root) return ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			ret.push_back(vector<int>());
			queue<TreeNode*> q2;
			while (!q.empty()) {
				auto* t = q.back();
				ret.back().push_back(t->val);
				if (t->left) q2.push(t->left);
				if (t->right) q2.push(t->right);
				q.pop();
			}
			q = q2;
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
