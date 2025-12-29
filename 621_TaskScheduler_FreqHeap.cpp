// Time : Beat 18.22%
// Memory : Beat 17.90%
// My algorithm is same as Leetcode Solution's Approach 1
class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		// only upper English letter as task name
		array<int, 26> freq;
		fill(freq.begin(), freq.end(), 0);
		for (char c: tasks) {
			int id = c-'A';
			++freq[id];
		}
		priority_queue<int> heap;
		for (int f: freq) {
			if (f>0) heap.push(f);
		}
		int num = n+1;
		int time = 0;
		while (heap.size()) {
			vector<int> tmpv;
			int pop_num = min((int)heap.size(), num);
			for (int i=0; i<pop_num; ++i) {
				tmpv.push_back(heap.top());
				heap.pop();
			}
			for (int i=0; i<pop_num; ++i) {
				if (tmpv[i] > 1) {
					heap.push(tmpv[i]-1);
				}
			}
			if (heap.size()) time += num;
			else time += pop_num;
		}
		return time;
	}
};
