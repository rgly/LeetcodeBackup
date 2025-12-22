/*
class Node {
bool val=false;
bool isLeaf=false;
Node* topLeft=nullptr;
Node* topRight=nullptr;
Node* bottomLeft=nullptr;
Node* bottomRight=nullptr;
Node(bool _val, bool _isLeaf) :val(_val), isLeaf(_isLeaf)
Node(bool _val, bool _isLeaf,
	Node* tl, Node* tr, Node* bl, Node* br) :
	val(_val), isLeaf(_isLeaf), topLeft(tl),
	topRight(tr), bottomLeft(bl), bottomRight(br)
*/

class Solution {
public:
	pair<int, Node*> build(vector<vector<int>>& grid,
			int top, int bottom, int left, int right) {
		assert(bottom > top);
		assert(right > left);
		assert(top < grid.size());
		assert(left < grid.size());
		int size = bottom - top;
		assert(right-left == size);
		if (size == 1) return {grid[top][left], nullptr};

		const int hs = size/2;
		const int vmid = top+hs;
		const int hmid = left+hs;
		auto p1 = build(grid, top,  vmid,   left, hmid);
		auto p2 = build(grid, top,  vmid,   hmid, right);
		auto p3 = build(grid, vmid, bottom, left, hmid);
		auto p4 = build(grid, vmid, bottom, hmid, right);
		auto& [tl, n1] = p1;
		auto& [tr, n2] = p2;
		auto& [bl, n3] = p3;
		auto& [br, n4] = p4;

		if (tl==tr && bl==br && tl==bl && tl>=0) {
			return {tl, nullptr};
		}
		if (!n1) n1 = new Node(tl, true);
		if (!n2) n2 = new Node(tr, true);
		if (!n3) n3 = new Node(bl, true);
		if (!n4) n4 = new Node(br, true);
		Node* node = new Node(true, false, n1, n2, n3, n4);
		return {-1, node};
	}
	// only 0s and 1s in the grid
	// construct compressed quad tree
	Node* construct(vector<vector<int>>& grid) {
		int size = grid.size();
		pair<int, Node*> p = build(grid, 0, size, 0, size);
		auto& [v, ptr] = p;
		if (!ptr) ptr = new Node(v, true);
		return ptr;
	}
};
