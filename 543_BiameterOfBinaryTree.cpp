// Time: Beats 100%
// Memory: Beats 44.12%
class Solution {
public:
	int longest=0;
	int findLongest(TreeNode* root) {
		if (!root) return 0;
		int l = findLongest(root->left);
		int r = findLongest(root->right);
		longest = max(longest, l+r);
		return max(l, r)+1;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		findLongest(root);
		return longest;
	}
};
