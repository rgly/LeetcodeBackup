// Time : Beats 34.54%
// Memory : Beats 32.71%
class Solution {
public:
	// utilize the BST nature, log time to solve
	TreeNode* bfsPQ(TreeNode* root, int p, int q) {
		if (!root) return nullptr;
		int val = root->val;
		bool RootPQ = (val == p) | (val == q);
		bool LeftP = p < val;
		bool LeftQ = q < val;
		if (RootPQ) return root;
		if (LeftP ^ LeftQ) return root;
		// Here means PQ on the same side
		auto* next = LeftP ? root->left : root->right;
		return bfsPQ(next, p, q);
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		return bfsPQ(root, p->val, q->val);
	}
};
