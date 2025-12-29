// Time : Beats 11.60%
// Memory : Beats 96.62%
class Solution {
public:
	int dfsGoodNodes(TreeNode* root, int threshold) {
		if (!root) return 0;
		int val = root->val;
		int next_threshold = max(val, threshold);
		int ChildGoodNodes = dfsGoodNodes(root->left, next_threshold)
					+ dfsGoodNodes(root->right, next_threshold);
		if (val >= threshold) {
			ChildGoodNodes += 1;
		}
		return ChildGoodNodes;
	}
	int goodNodes(TreeNode* root) {
		return dfsGoodNodes(root, INT_MIN);
	}
};
