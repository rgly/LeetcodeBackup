// Time: Beats 27.01% (1ms)
// Memory: Beats 5.19% (1ms)
class Solution {
public:
	void add(stack<TreeNode*>& st, TreeNode* cur) {
		while (cur) {
			st.push(cur);
			cur = cur->left;
		}
	}
	void recoverTree(TreeNode* root) {
		assert(root);
		TreeNode* left_node = nullptr;
		TreeNode* right_node = nullptr;
		bool FirstTime = true;
		stack<TreeNode*> st;
		add(st, root);
		TreeNode* last_node = st.top();;
		st.pop();
		if (last_node->right) add(st, last_node->right);

		while (!st.empty()) {
			TreeNode* cur = st.top();
			if (last_node->val > cur->val) {
				if (FirstTime) {
					left_node = last_node;
					FirstTime = false;
				}
				right_node = cur;
			}
			st.pop();
			if (cur->right) add(st, cur->right);
			last_node = cur;
		}
		assert(left_node);
		assert(right_node);
		swap(left_node->val, right_node->val);
	}
};
