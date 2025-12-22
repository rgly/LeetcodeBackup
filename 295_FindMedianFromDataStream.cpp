class MedianFinder {
public:
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
	int size=0;
	MedianFinder() {}
	void addNum(int num) {
		if (size==0 || num <= maxheap.top()) {
			maxheap.push(num);
		} else {
			minheap.push(num);
		}

		if (maxheap.size() > minheap.size()+1) {
			int v = maxheap.top();
			minheap.push(v);
			maxheap.pop();
		} else if (maxheap.size() < minheap.size()) {
			int v = minheap.top();
			maxheap.push(v);
			minheap.pop();
		}
		++size;
	}

	double findMedian() {
		if (maxheap.size() == minheap.size()+1) {
			return maxheap.top();
		} else if (maxheap.size() == minheap.size()) {
			return double(minheap.top() + maxheap.top())/2;
		} else {
			assert(0);
		}
	}
};
