// Time: Beats 19.53% (1ms)
// Memory: Beats 5.19% (1ms)
class Solution {
public:
	pair<int, TreeNode*> genMinTree(TreeNode* root, int pmax) {
		auto* r = new TreeNode(min(root->val, pmax));
		if (root->right) {
			pair<int, TreeNode*> p = genMinTree(root->right, pmax);
			r->val = min(r->val, p.first);
			r->right = p.second;
		}
		if (root->left) {
			pair<int, TreeNode*> p = genMinTree(root->left, r->val);
			r->left = p.second;
			return {p.first, r};
		}
		return {r->val, r};
	}
	pair<int, TreeNode*> genMaxTree(TreeNode* root, int pmin) {
		auto* r = new TreeNode(max(root->val, pmin));
		if (root->left) {
			pair<int, TreeNode*> p = genMaxTree(root->left, pmin);
			r->val = max(r->val, p.first);
			r->left = p.second;
		}
		if (root->right) {
			pair<int, TreeNode*> p = genMaxTree(root->right, r->val);
			r->right = p.second;
			return {p.first, r};
		}
		return {r->val, r};
	}

	// Partial sorted means prefixmax <= value <= suffixmin
	TreeNode* left_node = nullptr;
	TreeNode* right_node = nullptr;

	void checkPartialSort(
		TreeNode* root, TreeNode* prefixmax, TreeNode* suffixmin) {
		int v = root->val;
		if (root->left)
			checkPartialSort(root->left, prefixmax->left, suffixmin->left);
		if (root->right)
			checkPartialSort(root->right, prefixmax->right, suffixmin->right);

		if (!(prefixmax->val <= v) && (v <= suffixmin->val)) {
			assert(!right_node);
			right_node = root;
		}
		if ((prefixmax->val <= v) && !(v <= suffixmin->val)) {
			assert(!left_node);
			left_node = root;
		}
	}
	void recoverTree(TreeNode* root) {
		assert(root);
		TreeNode* prefixmax = genMaxTree(root, INT_MIN).second;
		TreeNode* suffixmin = genMinTree(root, INT_MAX).second;
		checkPartialSort(root, prefixmax, suffixmin);
		assert(left_node);
		assert(right_node);
		swap(left_node->val, right_node->val);
	}
};
