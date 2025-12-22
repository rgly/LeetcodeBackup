class Solution {
public:
	TreeNode* toBST(vector<int>& nums, int start, int end) {
		int size = end-start;
		if (size == 0) return nullptr;
		if (size == 1) return new TreeNode(nums[start]);

		int mid = (start + end)/2;
		assert(mid<end);
		auto* left = toBST(nums, start, mid);
		auto* right = toBST(nums, mid+1, end);
		auto* root = new TreeNode(nums[mid], left, right);
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return toBST(nums, 0, nums.size());
	}
};
