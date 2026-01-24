// Time : Beats 100%
// Memory : Beats 92.84%
class Solution {
public:
	bool isIdentical(TreeNode* root, TreeNode* subRoot) {
		if (root == subRoot) return true;
		else if (!root || !subRoot) return false;
		assert(root);
		assert(subRoot);
		if (root->val == subRoot->val) {
			return isIdentical(root->left, subRoot->left)
				&& isIdentical(root->right, subRoot->right);
		} else return false;
	}
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (root == subRoot) return true;
		else if (!root || !subRoot) return false;
		assert(root);
		assert(subRoot);
		if (isIdentical(root, subRoot)) return true;
		else {
			return isSubtree(root->left, subRoot)
					|| isSubtree(root->right, subRoot);
		}
	}
};
