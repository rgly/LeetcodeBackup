// Time : Beats 100%
// Memory : Beats 45.05%
class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> heap;
		for (int s: stones) {
			heap.push(s);
		}
		while(heap.size() >= 2) {
			int y = heap.top();
			heap.pop();
			int x = heap.top();
			heap.pop();
			int remain = y-x;
			if (remain > 0) heap.push(remain);
		}
		if (heap.empty()) return 0;
		else return heap.top();
	}
};
